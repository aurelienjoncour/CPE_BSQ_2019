/*
** EPITECH PROJECT, 2019
** CPE_BSQ
** File description:
** header for bsq
*/

#include <stdbool.h>

#ifndef BSQ_H_
#define BSQ_H_

typedef struct params_bsq params_bsq;

struct params_bsq {
    int x;
    int y;
    int size;
};

void my_show_word_array(int * const *tab, int nb_rows, int nb_cols);
int **mem_alloc_2d_array(int nb_rows, int nb_cols);
void free_2d_array(int **array_2d, int nb_rows);
int  **load_2d_arr_from_str(char const *src, int nb_rows, int nb_cols);
params_bsq bsq(int **tab, int nb_rows, int nb_cols);
void write_result(char *src, int *tab, params_bsq s);
char *fill_buffer(char const *filepath);
char *read_buffer(char *src, int *tab);
bool buffer_error(char *src, int nb_rows, int nb_cols);

#endif
