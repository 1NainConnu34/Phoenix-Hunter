/*
** EPITECH PROJECT, 2022
** day13
** File description:
** csfml
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "app.h"
#include "my.h"

int main(int argc, char const *argv[])
{
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;
    game_t *game = malloc(sizeof(game_t));
    menu_t *menu = malloc(sizeof(menu_t));
    end_t *end = malloc(sizeof(end_t));
    game->nbr_elem_list = 0;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' &&
    argv[1][2] == '\0')
        return description();
    for (int i = 100; i < 500; i += 100) {
        create_bird(game, -64, i, 0);
        create_bird(game, 800, i, 1);
    }
    create(game, menu, end, mode);
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &event))
            analyse_events(game, menu, end, event);
        update(game, menu, end);
    }
    return destroy(game, menu, end);
}
