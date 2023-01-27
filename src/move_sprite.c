/*
** EPITECH PROJECT, 2022
** day13
** File description:
** csfml
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "app.h"
#include "my.h"

void move_rect_hit_marker(game_t *game, int offset, int max_value)
{
    if (offset + game->hit_marker->rect_hit_marker.left < max_value)
        game->hit_marker->rect_hit_marker.left += offset;
    else {
        game->hit_marker->rect_hit_marker.left = 0;
        game->hit_marker->rect_hit_marker.top += 100;
    }
    if (game->hit_marker->rect_hit_marker.top == 600)
        game->hit_marker->rect_hit_marker.top = 0;
}

void move_rect_bird(bird_t *bird, int offset, int max_value)
{
    if (offset + bird->rect_bird.left < max_value)
        bird->rect_bird.left += offset;
    else
        bird->rect_bird.left = 0;
    if (bird->rect_bird.left == 0 && bird->rect_bird.top == 64) {
        reset_xy_bird(bird);
        bird->rect_bird.top = 0;
    }
}

void move_background(game_t *game)
{
    for (int i = 0; i < 6; i++) {
        if (game->list_back[i]->move_left +
        game->list_back[i]->rect_back.left < 800)
            game->list_back[i]->rect_back.left += game->list_back[i]->move_left;
        else
            game->list_back[i]->rect_back.left = 0;
    }
}
