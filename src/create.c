/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** create.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "app.h"
#include "my.h"

background_t *create_background(int move_left, char *texture)
{
    background_t *background = malloc(sizeof(background_t));

    background->sprite_back = sfSprite_create();
    background->texture_back = sfTexture_createFromFile(texture, NULL);
    background->move_left = move_left;
    background->rect_back.top = move_left * -10 - (2 << move_left);
    background->rect_back.left = 0;
    background->rect_back.width = 1600;
    background->rect_back.height = 800;
    sfSprite_setTexture(background->sprite_back, background->texture_back,
    sfTrue);
    return background;
}

bird_t *create_bird(game_t *game, int x, int y, int flip)
{
    bird_t *bird = malloc(sizeof(bird_t));

    bird->sprite_bird = sfSprite_create();
    bird->texture_bird = sfTexture_createFromFile(
        "img_png/Phoenix_SpriteSheet.png", NULL);
    bird->pos_bird.x = x;
    bird->pos_bird.y = y;
    bird->rect_bird.top = 0;
    bird->rect_bird.left = 0;
    bird->rect_bird.width = 64;
    bird->rect_bird.height = 64;
    if (flip == 1)
        bird->rect_bird.width = -64;
    sfSprite_setTexture(bird->sprite_bird, bird->texture_bird, sfTrue);
    bird->clock_bird = sfClock_create();
    game->list_bird[game->nbr_elem_list] = bird;
    game->nbr_elem_list += 1;
    return bird;
}

void create_hit_marker(game_t *game)
{
    game->hit_marker = malloc(sizeof(hit_marker_t));
    game->hit_marker->sprite_hit_marker = sfSprite_create();
    game->hit_marker->texture_hit_marker = sfTexture_createFromFile(
        "img_png/10_weaponhit_spritesheet.png", NULL);
    game->hit_marker->rect_hit_marker.top = 0;
    game->hit_marker->rect_hit_marker.left = 0;
    game->hit_marker->rect_hit_marker.width = 100;
    game->hit_marker->rect_hit_marker.height = 100;
    game->hit_marker->hit = 0;
    game->hit_marker->count = 0;
    sfSprite_setTexture(game->hit_marker->sprite_hit_marker,
    game->hit_marker->texture_hit_marker, sfTrue);
    game->hit_marker->clock_hit_marker = sfClock_create();
}

void create_back(game_t *game)
{
    game->list_back[0] = create_background(0, "img_png/sky.png");
    game->list_back[1] = create_background(1, "img_png/far-clouds.png");
    game->list_back[2] = create_background(2, "img_png/near-clouds.png");
    game->list_back[3] = create_background(3, "img_png/far-mountains.png");
    game->list_back[4] = create_background(4, "img_png/mountains.png");
    game->list_back[5] = create_background(5, "img_png/trees.png");
}

void create(game_t *game, menu_t *menu, end_t *end, sfVideoMode mode)
{
    sfVector2f pos = {245, 180};
    create_hit_marker(game);
    game->window = sfRenderWindow_create(mode, "Phoenix Hunter",
    sfClose, NULL);
    create_game(game);
    create_menu(menu);
    create_end(end);
    create_game2(game);
}
