/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** open bsq on windows
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "pixels_functions.h"
#include "graphicals_functions.h"
#include "structure.h"
#include "bsq.h"

void update_ressource(sfTexture *texture, framebuffer_t *fb, sfSprite *sprite,
                        sfRenderWindow *window)
{
    sfTexture_updateFromPixels(texture, fb->pixel, fb->width, fb->height, 0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfRenderWindow_drawSprite(window, sprite, NULL);
    sfRenderWindow_display(window);
}

void print_2d_array(char *src, framebuffer_t *fb, int *tab)
{
    int x = 0;
    int y = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        if (src[i] == '\n') {
            y++;
            x = 0;
        }
        else if (src[i] == '.') {
            draw_rectangle(fb, (sfVector2u){x * tab[1], y * tab[0]},
            (rectangle){tab[1], tab[0]}, sfWhite);
            x++;
        }
        else
            x++;
    }
}

void scalling(int *tab)
{
    if (tab[0] > tab[1]) {
        tab[0] = 1000 / tab[0];
        tab[1] = tab[0];
    }
    else {
        tab[1] = 1000 / tab[1];
        tab[0] = tab[1];
    }
}

int bsq_graphics(char *src, params_bsq bsq, int *tab)
{
    sfRenderWindow *window = create_windows(1000, 1000);
    sfEvent event;
    framebuffer_t *fb = framebuffer_create(1000, 1000);
    sfTexture *texture = sfTexture_create(fb->width, fb->height);
    sfSprite *sprite = sfSprite_create();

    if (!window)
        return EXIT_FAILURE;
    scalling(tab);
    while (sfRenderWindow_isOpen(window)) {
        print_2d_array(src, fb, tab);
        draw_rectangle(fb, (sfVector2u){tab[1] * bsq.y, bsq.x * tab[0]},
        (rectangle){bsq.size * tab[1], bsq.size * tab[0]}, sfRed);
        update_ressource(texture, fb, sprite, window);
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
    }
    destroy_ressource(sprite, texture, fb);
    return EXIT_SUCCESS;
}
