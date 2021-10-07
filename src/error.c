/*
** SYSTEM PROJECT, 2021
** error
** File description:
** file
*/

#include "error.h"

void print_error_and_exit(char *msg)
{
    fprintf(stderr, "Error : %s\n", msg);
    exit(EXIT_FAILURE);
}