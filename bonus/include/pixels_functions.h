/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** header for pixels_functions.c
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "structure.h"

#ifndef PIXELS_FUNCTIONS_H
#define PIXELS_FUNCTIONS_H

void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y,
                sfColor color);

int draw_line(framebuffer_t *fb, sfVector2i  point_a, sfVector2i  point_b,
                sfColor color);

void draw_square(framebuffer_t *fb, sfVector2u p, unsigned int s,
                    sfColor color);

void draw_rectangle(framebuffer_t *fb, sfVector2u p, rectangle parameter,
                    sfColor color);

#endif
