/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main function
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "bsq.h"

int bsq_graphics(char *src, params_bsq bsq, int *tab);

int main(int ac, char **av)
{
    int tab[2];
    char *src;
    int **array_2d;

    if (ac < 2)
        return 84;
    src = fill_buffer(av[1]);
    if (src == NULL)
        return 84;
    src = read_buffer(src, tab);
    if (src == NULL)
        return 84;
    if (buffer_error(src, tab[0], tab[1]))
        return 84;
    array_2d = load_2d_arr_from_str(src, tab[0], tab[1]);
    if (array_2d == NULL)
        return 84;
    bsq_graphics(src, bsq(array_2d, tab[0], tab[1]), tab);
    return 0;
}
