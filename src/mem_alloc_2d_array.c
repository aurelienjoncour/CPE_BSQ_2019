/*
** EPITECH PROJECT, 2019
** CPE_BSQ
** File description:
** function which allocates a 2d array and returns it's address
*/

#include <stdlib.h>

int **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    int **str_2d = malloc(sizeof(int *) * (nb_rows));

    if (str_2d == NULL)
        return NULL;
    for (int j = 0; j < nb_rows; j++) {
        str_2d[j] = malloc(sizeof(int) * (nb_cols));
        if (str_2d[j] == NULL)
            return NULL;
    }
    return str_2d;
}

void free_2d_array(int **array_2d, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++) {
        free(array_2d[i]);
    }
    free(array_2d);
}
