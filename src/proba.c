/*
** SYSTEM PROJECT, 2021
** proba
** File description:
** file
*/

#include "proba.h"

float *get_proba(char *path)
{
    char c = '\0';
    int len = 0;
    int counter[256] = {0};
    float *proba = malloc(sizeof(float) * 256);

    FILE *fd = fopen(path, "r");
    if (fd == NULL)
        print_error_and_exit("pathname invalide ou introuvable");
    while ((c = fgetc(fd)) != EOF) {
        len++;
        counter[(int)c]++;
    }

    for (int i = 0; i < 256; i++)
        if (counter[i] != 0)
            proba[i] = counter[i] / (float)len;
    fclose(fd);
    return proba;
}