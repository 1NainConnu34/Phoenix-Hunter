/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myhunter-alexandre.bret
** File description:
** assets2.c
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

int my_strlen(char const *str)
{
    int longueur = 0;
    while (*str != '\0') {
        longueur = longueur + 1;
        str++;
    }
    return longueur;
}
