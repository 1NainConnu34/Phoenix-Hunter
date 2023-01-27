##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

LDFLAGS = -I./include
CFLAGS = -l csfml-graphics -l csfml-system -l csfml-audio

SRC =   src/main.c \
		src/assets.c \
		src/assets2.c \
		src/assets_game.c \
		src/create.c \
		src/create2.c \
		src/create3.c \
		src/destroy.c \
		src/move_sprite.c \
		src/update.c \
		src/update2.c \
		src/update3.c \
		src/events.c \

OBJ = $(SRC:.c=.o)

TARGET = phoenix_hunter

all:		$(TARGET)

$(TARGET):	$(SRC)
		$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(TARGET)
clean:
	  	rm -rf $(OBJ)

fclean:		clean
	  	rm -rf $(TARGET)

re : fclean all
