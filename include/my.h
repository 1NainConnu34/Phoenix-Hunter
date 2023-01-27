/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** my.h
*/

#pragma once

#include <SFML/Graphics.h>
#include "app.h"

void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
void create(game_t *game, menu_t *menu, end_t *end, sfVideoMode mode);
void create_game2(game_t *game);
void create_menu(menu_t *menu);
void create_end(end_t *end);
void create_end2(end_t *end);
void create_game(game_t *game);
void create_back(game_t *game);
void update(game_t *game, menu_t *menu, end_t *end);
void update_game2(game_t *game, end_t *end);
void update_game(game_t *game, end_t *end);
void update_menu(menu_t *menu, game_t *game);
void update_end(end_t *end, game_t *game);
void update_bird(game_t *game, bird_t *bird);
void update_hit_marker(game_t *game);
void update_background(game_t *game);
void update_highscore(game_t *game);
int destroy(game_t *game, menu_t *menu, end_t *end);
void analyse_events(game_t *game, menu_t *menu, end_t *end, sfEvent event);
bird_t *create_bird(game_t *game, int x, int y, int flip);
void move_rect_hit_marker(game_t *game, int offset, int max_value);
void move_rect_bird(bird_t *bird, int offset, int max_value);
void move_background(game_t *game);
void reset_xy_bird(bird_t *bird);
int my_getnbr(char *str);
char *int_to_str(int nb);
char *my_strcpy(char *dest, char const *src);
background_t *create_background(int move_left, char *texture);
void reset_bird(game_t *game);
void check_if_hit_bird(game_t *game, int x, int y);
int my_strlen(char const *str);
int description(void);
