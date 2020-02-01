/*
** EPITECH PROJECT, 2019
** CPE_BSQ
** File description:
** load a rectangle in a 2d array
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include "bsq.h"
#include "my.h"

int **load_2d_arr_from_str(char const *src, int nb_rows, int nb_cols)
{
    int **tab = mem_alloc_2d_array(nb_rows, nb_cols);
    int len = 0;

    if (tab == NULL)
        return NULL;
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            if (src[len] == '.')
                tab[i][j] = 1;
            else if (src[len] == 'o')
                tab[i][j] = 0;
            len++;
        }
        len++;
    }
    return tab;
}
