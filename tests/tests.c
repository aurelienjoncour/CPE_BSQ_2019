/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** units test for BSQ
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "bsq.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (bsq, 100_100, .init = redirect_all_std)
{
    int tab[2];
    char *src;
    char *solved = "ok";
    int **array_2d;

    solved = fill_buffer("intermediate_map_100_100_solved");
    src = fill_buffer("intermediate_map_100_100");
    src = read_buffer(src, tab);
    array_2d = load_2d_arr_from_str(src, tab[0], tab[1]);
    write_result(src, tab, bsq(array_2d, tab[0], tab[1]));
    cr_assert_stdout_eq_str(solved);
}

Test (bsq, invalid_number)
{
    int tab[2] = {0};
    char *src = strdup("-12");

    cr_assert_eq(read_buffer(src, tab), NULL);
}

Test (bsq, error_buffer)
{
    cr_assert_not(buffer_error("oooo\noooo\n", 2, 4));
    cr_assert(buffer_error("ooo\noooo\n", 2, 4));
    cr_assert(buffer_error("o\no\no\no\n", 3, 1));
}
