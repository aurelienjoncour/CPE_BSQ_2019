/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** header for graphicals functions
*/

#include "structure.h"

#ifndef GRAPHICALS_FUNCTIONS_H_
#define GRAPHICALS_FUNCTIONS_H_

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

sfRenderWindow *create_windows(unsigned int w, unsigned int h);

void framebuffer_destroy(framebuffer_t *fb);

void framebuffer_reset(int width, int height, framebuffer_t *fb);

void destroy_ressource(sfSprite *sprite, sfTexture *texture, framebuffer_t *fb);

void update_ressource(sfTexture *texture, framebuffer_t *fb, sfSprite *sprite,
                        sfRenderWindow *window);

#endif
