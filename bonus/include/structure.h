/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** structure for framebuffer
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SFML/Config.h>

typedef struct framebuffer framebuffer_t;
struct framebuffer {
    sfUint8 *pixel;
    unsigned int width;
    unsigned int height;
};

typedef struct rectangle rectangle;
struct rectangle {
    unsigned int width;
    unsigned int height;
};


#endif
