/*
** SYSTEM PROJECT, 2021
** data
** File description:
** header file
*/

#ifndef DATA_H_
#define DATA_H_

#include "include.h"
#include "error.h"
#include "itoa.h"

#define MIN(a,b) (a < b) ? a : b
#define MAX(a,b) (a > b) ? a : b

typedef struct data_s {
    char *id;
    int fils_d;
    int fils_g;
    int pere;
    float proba;
}data_t;

typedef struct min_finder_s {
    int idx;
    float value;
}min_finder_t;

data_t *get_datas(float *proba);
void disp_data(data_t *data, float *proba);

#endif /* !DATA_H_ */