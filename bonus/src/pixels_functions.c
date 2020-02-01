/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** functions for fill framebuffer with form
*/

#include <SFML/Graphics.h>
#include "structure.h"
#include <math.h>

void put_pixel(framebuffer_t *framebuffer, unsigned int x, unsigned int y,
                sfColor color)
{
    framebuffer->pixel[(framebuffer->width * y + x) * 4] = color.r;
    framebuffer->pixel[(framebuffer->width * y + x) * 4 + 1] = color.g;
    framebuffer->pixel[(framebuffer->width * y + x) * 4 + 2] = color.b;
    framebuffer->pixel[(framebuffer->width * y + x) * 4 + 3] = color.a;
}

void draw_line(framebuffer_t *framebuffer, sfVector2i p_a, sfVector2i p_b,
                sfColor color)
{
    float a = ((float)p_b.y - (float)p_a.y) / ((float)p_b.x - (float)p_a.x);
    float b = (float)p_a.y - a * (float)p_a.x;
    sfVector2i tmp = {p_a.x, p_a.y};

    if (p_a.x - p_b.x == 0) {
        for (;tmp.y < p_b.y; tmp.y++)
            put_pixel(framebuffer, p_a.x, tmp.y, color);
        return;
    }
    for (; tmp.x <= p_b.x || tmp.x <= p_b.x; tmp.x++) {
        put_pixel(framebuffer, tmp.x, tmp.y, color);
        tmp.y = a * tmp.x + b;
    }
    tmp.x = p_a.x;
    tmp.y = p_a.y;
    while (tmp.y <= p_b.y) {
        put_pixel(framebuffer, tmp.x, tmp.y, color);
        tmp.y++;
        tmp.x = ((float)tmp.y - b) / a;
    }
}

void draw_square(framebuffer_t *framebuffer, sfVector2u position,
                unsigned int size, sfColor color)
{
    for (unsigned int x = 0; x < size; x++) {
        for (unsigned int y = 0; y < size; y++) {
            put_pixel(framebuffer, position.x + x, position.y + y, color);
        }
    }
}

void draw_rectangle(framebuffer_t *framebuffer, sfVector2u position,
                        rectangle parameter, sfColor color)
{
    for (unsigned int x = 0; x < parameter.width; x++) {
        for (unsigned int y = 0; y < parameter.height; y++) {
            put_pixel(framebuffer, position.x + x, position.y + y, color);
        }
    }
}

sfColor reboot(sfColor color_src, sfColor color)
{
    color.r = color_src.r;
    color.g = color_src.g;
    color.b = color_src.b;
    color.a = color_src.a;
    return color;
}
