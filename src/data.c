/*
** EPITECH PROJECT, 2021
** data
** File description:
** file
*/

#include "data.h"

int count_data(float *proba)
{
    int counter = 0;

    for (int i = 0; i != 255; i++)
        if (proba[i] != 0)
            counter++;
    return counter;
}

void disp_data(data_t *data, float *proba)
{
    int nb_data = count_data(proba);
    int data_size = 2 * nb_data - 1;

    printf("%10s\t%10s\t%10s\t%10s\t%10s\n", "caratère", "fils gauche", "fils droit", "père", "probabilité");
    for (int i = 0; i < data_size; i++) {
        printf("%10s\t%10d\t%10d\t%10d\t%10.2f\n", data[i].id, data[i].fils_g, data[i].fils_d, data[i].pere, data[i].proba);
    }
}

min_finder_t *get_min_p(data_t *data, int data_size)
{
    min_finder_t *min_f = malloc(sizeof(min_finder_t) * 2);
    min_f[0].idx = -1;
    min_f[0].value = 1;
    min_f[1].idx = -1;
    min_f[1].value = 1;
    int max = 0;

    for (int i = 0; i < data_size; i++) {
        if (data[i].id != NULL && data[i].pere == -1) {
            max = MAX(min_f[0].value, min_f[1].value) == min_f[0].value ? 0 : 1;
            if (MIN(data[i].proba, min_f[max].value) == data[i].proba) {
                min_f[max].idx = i;
                min_f[max].value = data[i].proba;
            }
        }
    }
    return min_f;
}

data_t *calc_data(data_t *data, int data_size)
{
    min_finder_t *min_f;
    for (int i = 0; i < data_size; i++) {
        if (data[i].id == NULL) {
            min_f = get_min_p(data, data_size);
            data[i].id = malloc(sizeof(char) * (strlen(data[min_f[0].idx].id + strlen(data[min_f[1].idx].id))));
            strcat(strcat(data[i].id, data[min_f[0].idx].id), data[min_f[1].idx].id);
            data[i].fils_g = min_f[0].idx;
            data[i].fils_d = min_f[1].idx;
            data[i].proba = min_f[0].value + min_f[1].value;
            data[min_f[0].idx].pere = i;
            data[min_f[1].idx].pere = i;
        }
    }
    return data;
}

data_t *get_datas(float *proba)
{
    if (proba == NULL)
        print_error_and_exit("La table de probabilité ou le fichier à crypter ne doivent pas être vides");
    int idx = 0;
    int nb_data = count_data(proba); // compte le nombre de caractère différents présents dans le fichier à crypter
    int data_size = 2 * nb_data - 1; //2 * nb_data - 1 = nbr de feuille (nb_data) + nb_noeuds parents (nb_data - 1)
    data_t *data = malloc(sizeof(data_t) * data_size);
    char tmp = 0;

    for (int i = 0; i != 255; i++) {
        if (proba[i] != 0) {
            tmp = i;
            data[idx].id = malloc(sizeof(char) * 1);
            sprintf(data[idx].id, "%c", tmp);
            data[idx].fils_d = -1;
            data[idx].fils_g = -1;
            data[idx].pere = -1;
            data[idx].proba = proba[i];
            idx++;
        }
    }
    for (; idx < data_size; idx++) {
        data[idx].id = NULL;
        data[idx].fils_d = -1;
        data[idx].fils_g = -1;
        data[idx].pere = -1;
        data[idx].proba = -1.0;
    }
    data = calc_data(data, data_size);
    return data;
}