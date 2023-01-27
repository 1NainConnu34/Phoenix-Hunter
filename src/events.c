/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** events.c
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "app.h"
#include "my.h"

void analyse_events_end2(game_t *game, menu_t *menu, end_t *end, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x <= 550 &&
        event.mouseButton.x >= 250 && event.mouseButton.y <= 440 &&
        event.mouseButton.y >= 365) {
            sfSound_stop(game->sound_shoot);
            sfSound_destroy(game->sound_shoot);
            sfSoundBuffer_destroy(game->sound_buffer_shoot);
            create_game(game);
            create_game2(game);
            reset_bird(game);
            game->game_is_running = false;
            end->end_is_running = false;
            menu->menu_is_running = true;
        }
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x <= 550 &&
        event.mouseButton.x >= 250 && event.mouseButton.y <= 565 &&
        event.mouseButton.y >= 490)
            sfRenderWindow_close(game->window);
}

void analyse_events_end(game_t *game, menu_t *menu, end_t *end, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x <= 550 &&
        event.mouseButton.x >= 250 && event.mouseButton.y <= 315 &&
        event.mouseButton.y >= 240) {
            sfSound_stop(game->sound_shoot);
            sfSound_destroy(game->sound_shoot);
            sfSoundBuffer_destroy(game->sound_buffer_shoot);
            create_game(game);
            create_game2(game);
            reset_bird(game);
            end->end_is_running = false;
            game->game_is_running = true;
        }
    analyse_events_end2(game, menu, end, event);
}

void analyse_events_menu(menu_t *menu, game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x <= 550
        && event.mouseButton.x >= 250 && event.mouseButton.y <= 525 &&
        event.mouseButton.y >= 425)
            sfRenderWindow_close(game->window);
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.x <= 550
        && event.mouseButton.x >= 250 && event.mouseButton.y <= 375 &&
        event.mouseButton.y >= 275) {
            menu->menu_is_running = false;
            game->game_is_running = true;
        }
}

void analyse_events_game(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        sfSound_stop(game->sound_shoot);
        sfSound_play(game->sound_shoot);
        check_if_hit_bird(game, event.mouseButton.x, event.mouseButton.y);
        game->hit_marker->pos_hit_marker.x = event.mouseButton.x - 50;
        game->hit_marker->pos_hit_marker.y = event.mouseButton.y - 50;
        game->hit_marker->hit = 1;
    }
}

void analyse_events(game_t *game, menu_t *menu, end_t *end, sfEvent event)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->window);
    game->cursorPosition.x = pos.x - 16;
    game->cursorPosition.y = pos.y - 16;
    if (game->game_is_running == true)
        analyse_events_game(game, event);
    if (menu->menu_is_running == true)
        analyse_events_menu(menu, game, event);
    if (end->end_is_running == true)
        analyse_events_end(game, menu, end, event);
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
}
