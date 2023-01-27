/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** create3.c
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

void create_end2(end_t *end)
{
    end->sprite_menu = sfSprite_create();
    end->texture_menu = sfTexture_createFromFile("img_png/MENU.png", NULL);
    end->menuPosition.x = 250;
    end->menuPosition.y = 365;
    end->sprite_quit = sfSprite_create();
    end->texture_quit = sfTexture_createFromFile("img_png/QUIT_END.png", NULL);
    end->quitPosition.x = 250;
    end->quitPosition.y = 490;
    end->highscorePosition.x = 300;
    end->highscorePosition.y = 165;
    end->highscoreText = sfText_create();
}
