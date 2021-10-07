/*
** SYSTEM PROJECT, 2021
** main
** File description:
** file
*/

#include "main.h"

void usage()
{
    printf("./huffman pathname\n\
    \tpathname : string donnant le chemin absolu ou relatif du fichier à compresser\n\
    \t--help OU -h : affiche cette aide d'utilisation\n");
    exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    if (ac != 2)
        print_error_and_exit("Vous devez passer au moins deux arguments...\nUtilisez les options -h OU --help pour plus d'informations");
    if (strcmp(av[1], "-h") == 0 || strcmp(av[1], "--help") == 0)
        usage();

    float *proba = get_proba(av[1]);
    data_t *data = get_datas(proba);

    disp_data(data, proba);
    return EXIT_SUCCESS;
}