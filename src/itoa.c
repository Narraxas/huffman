/*
** SYSTEM PROJECT, 2021
** itoa
** File description:
** file
*/

#include "itoa.h"

int intlen(int nbr)
{
    int digit_nbr = (int)floor(log(nbr) / log(10)) + 1;

    if (nbr == 0)
        return 1;
    return digit_nbr;
}

char *my_itoa(int nbr)
{
    int len = intlen(nbr);
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = len - 1; i != -1; i--) {
        str[i] = (nbr % 10) + 48;
        nbr /= 10;
    }
    return str;
}