/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** update.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "app.h"
#include "my.h"

void update_hit_marker(game_t *game)
{
    game->hit_marker->time_hit_marker = sfClock_getElapsedTime(
        game->hit_marker->clock_hit_marker);
    game->hit_marker->seconds_hit_marker =
    game->hit_marker->time_hit_marker.microseconds / 1000000.0;
    if (game->hit_marker->seconds_hit_marker > 0.001 &&
    game->hit_marker->hit == 1) {
        move_rect_hit_marker(game, 200, 600);
        sfClock_restart(game->hit_marker->clock_hit_marker);
        sfSprite_setPosition(game->hit_marker->sprite_hit_marker,
        game->hit_marker->pos_hit_marker);
        game->hit_marker->count += 1;
        if (game->hit_marker->count == 18) {
            game->hit_marker->count = 0;
            game->hit_marker->hit = 0;
        }
    }
    sfSprite_setTextureRect(game->hit_marker->sprite_hit_marker,
    game->hit_marker->rect_hit_marker);
    sfRenderWindow_drawSprite(game->window, game->hit_marker->sprite_hit_marker,
    NULL);
}

void update_bird(game_t *game, bird_t *bird)
{
    bird->time_bird = sfClock_getElapsedTime(bird->clock_bird);
    bird->seconds_bird = bird->time_bird.microseconds / 1000000.0;
    if (bird->rect_bird.width > 0)
        bird->pos_bird.x += rand() % 4;
    else
        bird->pos_bird.x -= rand() % 4;
    bird->pos_bird.y += rand() % 2 == 0 ? rand() % 5 : rand() % 5 * -1;
    if (bird->pos_bird.x < -64 || bird->pos_bird.x > 800 ||
    bird->pos_bird.y < 0 || bird->pos_bird.y > 600)
        reset_xy_bird(bird);
    if (bird->seconds_bird > 0.05) {
        move_rect_bird(bird, 64, 384);
        sfClock_restart(bird->clock_bird);
        sfSprite_setPosition(bird->sprite_bird, bird->pos_bird);
    }
    sfSprite_setTextureRect(bird->sprite_bird, bird->rect_bird);
    sfRenderWindow_drawSprite(game->window, bird->sprite_bird, NULL);
}

void update_background(game_t *game)
{
    move_background(game);
    for (int i = 0; i < 6; i++) {
        sfSprite_setTextureRect(game->list_back[i]->sprite_back,
        game->list_back[i]->rect_back);
        sfRenderWindow_drawSprite(game->window,
        game->list_back[i]->sprite_back, NULL);
    }
}

void update_menu(menu_t *menu, game_t *game)
{
    for (int i = 0; i < 6; i++) {
        sfSprite_setTextureRect(menu->list_back[i]->sprite_back,
        menu->list_back[i]->rect_back);
        sfRenderWindow_drawSprite(game->window,
        menu->list_back[i]->sprite_back, NULL);
    }
    sfSprite_setTexture(menu->sprite_title, menu->texture_title, sfTrue);
    sfSprite_setPosition(menu->sprite_title, menu->titlePosition);
    sfSprite_setTexture(menu->sprite_play, menu->texture_play, sfTrue);
    sfSprite_setPosition(menu->sprite_play, menu->playPosition);
    sfSprite_setTexture(menu->sprite_quit, menu->texture_quit, sfTrue);
    sfSprite_setPosition(menu->sprite_quit, menu->quitPosition);
    sfRenderWindow_drawSprite(game->window, menu->sprite_title, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite_quit, NULL);
    sfRenderWindow_drawSprite(game->window, menu->sprite_play, NULL);
}

void update(game_t *game, menu_t *menu, end_t *end)
{
    sfRenderWindow_clear(game->window, sfBlack);
    if (game->game_is_running == true)
        update_game(game, end);
    else if (menu->menu_is_running == true)
        update_menu(menu, game);
    else
        update_end(end, game);
    sfRenderWindow_display(game->window);
}
