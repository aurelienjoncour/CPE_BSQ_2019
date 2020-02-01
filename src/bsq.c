/*
** EPITECH PROJECT, 2019
** CPE_BSQ
** File description:
** find the biggest square
*/

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

static int min(int n1, int n2, int n3)
{
    if (n1 < n2) {
        if (n1 < n3)
            return n1;
        else
            return n3;
    }
    else if (n2 < n3)
        return n2;
    else
        return n3;
}

void write_result(char *src, int *tab, params_bsq s)
{
    int curseur = (tab[1] + 1) * s.x + s.y;

    for (int j = 0; j < s.size; j++) {
        for (int i = 0; i < s.size; i++) {
            src[curseur + i] = 'x';
        }
        curseur += tab[1] + 1;
    }
    write(1, src, (tab[0] * (tab[1] + 1)));
    free(src);
}

params_bsq bsq(int **tab, int nb_rows, int nb_cols)
{
    params_bsq bsq = {0, 0, 0};

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            if (i == 0 || j == 0);
            else if (tab[i][j] > 0)
                tab[i][j] = 1 + min(tab[i][j-1], tab[i-1][j], tab[i-1][j-1]);
            if (tab[i][j] > bsq.size) {
                bsq.size = tab[i][j];
                bsq.x = i - (bsq.size - 1);
                bsq.y = j - (bsq.size - 1);
            }
        }
    }
    free_2d_array(tab, nb_rows);
    return bsq;
}
