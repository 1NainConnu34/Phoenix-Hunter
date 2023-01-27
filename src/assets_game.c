/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** assets2.c
*/

#include <stdlib.h>
#include "app.h"
#include "my.h"

void reset_xy_bird(bird_t *bird)
{
    if (bird->rect_bird.width > 0)
        bird->pos_bird.x = (rand() % 125 * -1) - 64;
    else
        bird->pos_bird.x = rand() % 125 + 800;
    bird->pos_bird.y = rand() % 450 + 100;
}

void check_if_hit_bird(game_t *game, int x, int y)
{
    for (int i = 0; i < game->nbr_elem_list; i++) {
        if (x >= game->list_bird[i]->pos_bird.x &&
        x <= game->list_bird[i]->pos_bird.x + 64 &&
        y >= game->list_bird[i]->pos_bird.y &&
        y <= game->list_bird[i]->pos_bird.y + 64 &&
        game->list_bird[i]->rect_bird.top != 64) {
            game->list_bird[i]->rect_bird.top = 64;
            game->list_bird[i]->rect_bird.left = 0;
            game->score_int += 1;
            my_strcpy(game->score_char + 8, int_to_str(game->score_int));
        }
    }
}

void reset_bird(game_t *game)
{
    game->nbr_elem_list = 0;

    for (int i = 0; i < 8; i++)
        free(game->list_bird[i]);
    for (int i = 100; i < 500; i += 100) {
        create_bird(game, -64, i, 0);
        create_bird(game, 800, i, 1);
    }
}

int description(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_hunter\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     Kill the most phoenix in 30 seconds ");
    my_putstr("by clicking on them to gain a point.\n");
    return 0;
}
