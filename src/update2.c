/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** update2.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "app.h"
#include "my.h"

void update_game3(game_t *game)
{
    sfSprite_setTexture(game->sprite_cursor, game->texture_cursor, sfTrue);
    sfSprite_setPosition(game->sprite_cursor, game->cursorPosition);
    if (game->cursorPosition.x >= -16 && game->cursorPosition.x <= 784 &&
    game->cursorPosition.y >= -16 && game->cursorPosition.y <= 584)
        sfRenderWindow_drawSprite(game->window, game->sprite_cursor, NULL);
}

void update_game2(game_t *game, end_t *end)
{
    sfText_setPosition(game->scoreText, game->scorePosition);
    sfText_setString(game->scoreText, game->score_char);
    sfText_setColor(game->scoreText, sfRed);
    sfText_setFont(game->scoreText, game->scoreFont);
    sfText_setPosition(game->secondeText, game->secondePosition);
    sfText_setString(game->secondeText, game->seconde_char);
    sfText_setColor(game->secondeText, sfRed);
    sfText_setFont(game->secondeText, game->scoreFont);
    sfRenderWindow_drawText(game->window, game->scoreText, NULL);
    sfRenderWindow_drawText(game->window, game->secondeText, NULL);
    if (game->seconde_int == 0) {
        sfRenderWindow_setMouseCursorVisible(game->window, true);
        game->game_is_running = false;
        end->end_is_running = true;
        if (game->score_int > game->highscore) {
            game->highscore = game->score_int;
            my_strcpy(game->highscore_char + 12, int_to_str(game->highscore));
            update_highscore(game);
        }
    }
}

void update_game(game_t *game, end_t *end)
{
    sfRenderWindow_setMouseCursorVisible(game->window, false);
    game->time_back = sfClock_getElapsedTime(game->clock_back);
    game->seconds_back = game->time_back.microseconds / 1000000.0;
    update_background(game);
    game->time_game = sfClock_getElapsedTime(game->clock_game);
    game->seconds_game = game->time_game.microseconds / 1000000.0;
    if (game->seconds_game >= 1) {
        game->seconde_int -= 1;
        my_strcpy(game->seconde_char + 16, int_to_str(game->seconde_int));
        sfClock_restart(game->clock_game);
    }
    update_hit_marker(game);
    for (int i = 0; i < game->nbr_elem_list; i++) {
        update_bird(game, game->list_bird[i]);
    }
    update_game2(game, end);
    update_game3(game);
}

void update_end2(end_t *end, game_t *game)
{
    sfText_setPosition(game->scoreText, game->scorePosition);
    sfText_setString(game->scoreText, game->score_char);
    sfText_setColor(game->scoreText, sfRed);
    sfText_setFont(game->scoreText, game->scoreFont);
    sfText_setPosition(end->highscoreText, end->highscorePosition);
    sfText_setString(end->highscoreText, game->highscore_char);
    sfText_setColor(end->highscoreText, sfRed);
    sfText_setFont(end->highscoreText, game->scoreFont);
    sfSprite_setTexture(end->sprite_restart, end->texture_restart, sfTrue);
    sfSprite_setPosition(end->sprite_restart, end->restartPosition);
    sfSprite_setTexture(end->sprite_menu, end->texture_menu, sfTrue);
    sfSprite_setPosition(end->sprite_menu, end->menuPosition);
    sfSprite_setTexture(end->sprite_quit, end->texture_quit, sfTrue);
    sfSprite_setPosition(end->sprite_quit, end->quitPosition);
}

void update_end(end_t *end, game_t *game)
{
    for (int i = 0; i < 6; i++) {
        sfSprite_setTextureRect(end->list_back[i]->sprite_back,
        end->list_back[i]->rect_back);
        sfRenderWindow_drawSprite(game->window,
        end->list_back[i]->sprite_back, NULL);
    }
    update_end2(end, game);
    sfRenderWindow_drawSprite(game->window, end->sprite_restart, NULL);
    sfRenderWindow_drawSprite(game->window, end->sprite_menu, NULL);
    sfRenderWindow_drawSprite(game->window, end->sprite_quit, NULL);
    sfRenderWindow_drawText(game->window, game->scoreText, NULL);
    sfRenderWindow_drawText(game->window, end->highscoreText, NULL);
}
