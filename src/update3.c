/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** update3.c
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

void update_highscore(game_t *game)
{
    int fd = open("src/highscore.txt", O_WRONLY);
    write(fd, int_to_str(game->highscore),
    my_strlen(int_to_str(game->highscore)));
    close(fd);
}
