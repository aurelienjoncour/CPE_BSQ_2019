/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** fonction for buffer
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "bsq.h"

char *fill_buffer(char const *filepath)
{
    int fd;
    char *src;
    struct stat statbuf;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    stat(filepath, &statbuf);
    src = malloc(sizeof(char) * (statbuf.st_size + 1));
    if (src == NULL)
        return NULL;
    read(fd, src, statbuf.st_size);
    src[statbuf.st_size] = '\0';
    close(fd);
    return src;
}

char *read_buffer(char *src, int *tab)
{
    int len_first_line = 1;
    char *src_cpy;

    tab[0] = my_getnbr(src);
    if (tab[0] < 1) {
        free(src);
        return NULL;
    }
    for (int i = tab[0]; i > 0 ;len_first_line++)
        i /= 10;
    tab[1] = (my_strlen(src) - len_first_line - tab[0]) / tab[0];
    src_cpy = my_strdup(src + len_first_line);
    if (src_cpy == NULL)
        return NULL;
    free(src);
    return src_cpy;
}

bool buffer_error(char *src, int nb_rows, int nb_cols)
{
    int nb_lines = 0;
    int nb_char_per_line = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        nb_char_per_line++;
        if (src[i] == '\n') {
            nb_lines++;
            if (nb_cols != nb_char_per_line - 1)
                return true;
            nb_char_per_line = 0;
        }
    }
    if (nb_lines != nb_rows)
        return true;
    return false;
}
