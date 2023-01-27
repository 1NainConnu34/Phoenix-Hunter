/*
** EPITECH PROJECT, 2022
** app h
** File description:
** app h
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdbool.h>

#pragma once

typedef struct hit_marker {
    sfIntRect rect_hit_marker;
    sfTexture *texture_hit_marker;
    sfSprite *sprite_hit_marker;
    sfClock *clock_hit_marker;
    sfTime time_hit_marker;
    float seconds_hit_marker;
    sfVector2f pos_hit_marker;
    int hit;
    int count;
} hit_marker_t;

typedef struct bird {
    sfIntRect rect_bird;
    sfTexture *texture_bird;
    sfSprite *sprite_bird;
    sfClock *clock_bird;
    sfTime time_bird;
    float seconds_bird;
    sfVector2f pos_bird;
} bird_t;

typedef struct background {
    sfIntRect rect_back;
    sfTexture *texture_back;
    sfSprite *sprite_back;
    int move_left;
} background_t;

typedef struct game {
    bool game_is_running;
    sfRenderWindow *window;
    background_t *list_back[6];
    sfClock *clock_back;
    sfTime time_back;
    float seconds_back;
    int nbr_elem_list;
    bird_t *list_bird[8];
    sfText *scoreText;
    sfVector2f scorePosition;
    sfFont *scoreFont;
    int score_int;
    char *score_char;
    sfClock *clock_game;
    sfTime time_game;
    float seconds_game;
    sfText *secondeText;
    sfVector2f secondePosition;
    int seconde_int;
    char *seconde_char;
    hit_marker_t *hit_marker;
    int highscore;
    char *highscore_char;
    sfSprite *sprite_cursor;
    sfTexture *texture_cursor;
    sfVector2f cursorPosition;
    sfSoundBuffer *sound_buffer_shoot;
    sfSound *sound_shoot;
} game_t;

typedef struct menu {
    bool menu_is_running;
    background_t *list_back[6];
    sfSprite *sprite_title;
    sfTexture *texture_title;
    sfVector2f titlePosition;
    sfSprite *sprite_play;
    sfTexture *texture_play;
    sfVector2f playPosition;
    sfSprite *sprite_quit;
    sfTexture *texture_quit;
    sfVector2f quitPosition;
} menu_t;

typedef struct end {
    bool end_is_running;
    background_t *list_back[6];
    sfSprite *sprite_restart;
    sfTexture *texture_restart;
    sfVector2f restartPosition;
    sfSprite *sprite_menu;
    sfTexture *texture_menu;
    sfVector2f menuPosition;
    sfSprite *sprite_quit;
    sfTexture *texture_quit;
    sfVector2f quitPosition;
    sfText *highscoreText;
    sfVector2f highscorePosition;
} end_t;
