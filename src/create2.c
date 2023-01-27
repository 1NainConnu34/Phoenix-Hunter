/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** create2.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "app.h"
#include "my.h"

void create_game2(game_t *game)
{
    game->sound_buffer_shoot = sfSoundBuffer_createFromFile("sound/fusil.ogg");
    game->sound_shoot = sfSound_create();
    sfSound_setBuffer(game->sound_shoot, game->sound_buffer_shoot);
    game->scorePosition.x = 650;
    game->scorePosition.y = 20;
    game->scoreFont = sfFont_createFromFile("Roboto-Medium.ttf");
    sfRenderWindow_setFramerateLimit(game->window, 60);
}

void create_highscore(game_t *game)
{
    int fd = open("src/highscore.txt", O_RDONLY);
    char *buffer = malloc(1);
    int read_value = read(fd, buffer, 1);
    int temp = 12;

    game->highscore_char = malloc(20);
    my_strcpy(game->highscore_char, "Highscore : ");
    while (read_value != 0) {
        if (buffer[0] >= '0' && buffer[0] <= '9') {
            my_strcpy(game->highscore_char + temp, buffer);
            temp++;
        } else
            break;
        read_value = read(fd, buffer, 1);
    }
    game->highscore_char[temp] = '\0';
    game->highscore = my_getnbr(game->highscore_char);
    close(fd);
    free(buffer);
}

void create_game(game_t *game)
{
    create_back(game);
    game->game_is_running = false;
    game->clock_game = sfClock_create();
    game->clock_back = sfClock_create();
    game->secondeText = sfText_create();
    game->seconde_int = 30;
    game->seconde_char = malloc(24);
    my_strcpy(game->seconde_char, "Temps restant : 30");
    game->secondePosition.x = 20;
    game->secondePosition.y = 20;
    game->scoreText = sfText_create();
    game->score_int = 0;
    game->score_char = malloc(16);
    my_strcpy(game->score_char, "Score : 0");
    create_highscore(game);
    game->sprite_cursor = sfSprite_create();
    game->texture_cursor = sfTexture_createFromFile("img_png/crosshair.png",
    NULL);
}

void create_menu(menu_t *menu)
{
    menu->menu_is_running = true;
    menu->list_back[0] = create_background(0, "img_png/sky.png");
    menu->list_back[1] = create_background(0, "img_png/far-clouds.png");
    menu->list_back[2] = create_background(0, "img_png/near-clouds.png");
    menu->list_back[3] = create_background(0, "img_png/far-mountains.png");
    menu->list_back[4] = create_background(0, "img_png/mountains.png");
    menu->list_back[5] = create_background(0, "img_png/trees.png");
    menu->sprite_title = sfSprite_create();
    menu->texture_title = sfTexture_createFromFile(
    "img_png/phoenix_hunter.png", NULL);
    menu->titlePosition.x = 200;
    menu->titlePosition.y = -5;
    menu->sprite_play = sfSprite_create();
    menu->texture_play = sfTexture_createFromFile("img_png/PLAY.png", NULL);
    menu->playPosition.x = 250;
    menu->playPosition.y = 275;
    menu->sprite_quit = sfSprite_create();
    menu->texture_quit = sfTexture_createFromFile("img_png/QUIT.png", NULL);
    menu->quitPosition.x = 250;
    menu->quitPosition.y = 425;
}

void create_end(end_t *end)
{
    end->end_is_running = false;
    end->list_back[0] = create_background(0, "img_png/sky.png");
    end->list_back[1] = create_background(0, "img_png/far-clouds.png");
    end->list_back[2] = create_background(0, "img_png/near-clouds.png");
    end->list_back[3] = create_background(0, "img_png/far-mountains.png");
    end->list_back[4] = create_background(0, "img_png/mountains.png");
    end->list_back[5] = create_background(0, "img_png/trees.png");
    end->sprite_restart = sfSprite_create();
    end->texture_restart = sfTexture_createFromFile("img_png/RESTART.png",
    NULL);
    end->restartPosition.x = 250;
    end->restartPosition.y = 240;
    create_end2(end);
}
