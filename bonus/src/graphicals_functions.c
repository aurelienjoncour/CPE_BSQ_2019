/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** gestion of windows, image, buffer
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <stdlib.h>
#include "structure.h"
#include "pixels_functions.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *ptr = malloc(sizeof(framebuffer_t));

    ptr->pixel = malloc(sizeof(sfUint8) * (width * height * 4));
    ptr->height = height;
    ptr->width = width;
    return (ptr);
}

void framebuffer_reset(int width, int height, framebuffer_t *fb)
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            put_pixel(fb, j, i, sfBlack);
        }
    }
}

void framebuffer_destroy(framebuffer_t *fb)
{
    free(fb->pixel);
    free(fb);
}

sfRenderWindow *create_windows(unsigned int w, unsigned int h)
{
    sfVideoMode video_mode = {w, h, 32};
    sfRenderWindow *window;

    window = sfRenderWindow_create(video_mode, "BSQ", sfDefaultStyle, NULL);
    return (window);
}

void destroy_ressource(sfSprite *sprite, sfTexture *texture, framebuffer_t *fb)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    framebuffer_destroy(fb);
}
