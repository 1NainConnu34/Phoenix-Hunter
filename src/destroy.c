/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** destroy.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "app.h"
#include "my.h"

void destroy_bird(bird_t *bird)
{
    sfSprite_destroy(bird->sprite_bird);
    sfClock_destroy(bird->clock_bird);
    sfTexture_destroy(bird->texture_bird);
}

void destroy_menu(menu_t *menu)
{
    sfSprite_destroy(menu->sprite_title);
    sfSprite_destroy(menu->sprite_play);
    sfSprite_destroy(menu->sprite_quit);
    sfTexture_destroy(menu->texture_title);
    sfTexture_destroy(menu->texture_play);
    sfTexture_destroy(menu->texture_quit);
    for (int i = 0; i < 6; i++)
        free(menu->list_back[i]);
}

void destroy_end(end_t *end)
{
    sfSprite_destroy(end->sprite_restart);
    sfTexture_destroy(end->texture_restart);
    sfSprite_destroy(end->sprite_menu);
    sfTexture_destroy(end->texture_menu);
    sfSprite_destroy(end->sprite_quit);
    sfTexture_destroy(end->texture_quit);
    sfText_destroy(end->highscoreText);
    for (int i = 0; i < 6; i++)
        free(end->list_back[i]);
}

void destroy_game(game_t *game)
{
    sfRenderWindow_close(game->window);
    sfText_destroy(game->scoreText);
    sfText_destroy(game->secondeText);
    sfClock_destroy(game->clock_game);
    sfSprite_destroy(game->hit_marker->sprite_hit_marker);
    sfSprite_destroy(game->sprite_cursor);
    sfClock_destroy(game->hit_marker->clock_hit_marker);
    sfTexture_destroy(game->hit_marker->texture_hit_marker);
    free(game->highscore_char);
    free(game->score_char);
    free(game->seconde_char);
    for (int i = 0; i < 6; i++)
        free(game->list_back[i]);
    for (int i = 0; i < game->nbr_elem_list; i++) {
        destroy_bird(game->list_bird[i]);
    }
    sfSound_stop(game->sound_shoot);
    sfSound_destroy(game->sound_shoot);
    sfSoundBuffer_destroy(game->sound_buffer_shoot);
}

int destroy(game_t *game, menu_t *menu, end_t *end)
{
    destroy_menu(menu);
    destroy_end(end);
    destroy_game(game);
    sfRenderWindow_destroy(game->window);
    free(game);
    free(menu);
    free(end);
    return 0;
}
