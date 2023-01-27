/*
** EPITECH PROJECT, 2022
** bsmyhunter
** File description:
** print_fct.c
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + '0');
        return 0;
    }
    my_put_nbr(nb / 10);
    my_putchar(nb % 10 + '0');
}

int my_getnbr(char *str)
{
    int signe = 0;
    int i = 0;
    int nbr = 0;
    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '-')
            signe = signe + 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        if (nbr == 214748364 && str[i] == '8' && signe % 2 == 1
        && (str[i + 1] < '0' || str[i + 1] > '9'))
            return -2147483648;
        nbr = 10 * nbr + str[i] - 48;
        i++;
        if (nbr < 0)
        return 0;
    }
    if (signe % 2 == 1)
        nbr = nbr * -1;
    return nbr;
}

char *int_to_str(int nb)
{
    char *str = malloc(10);
    int len = 0;
    int nb_bis = nb;
    int i = 0;

    while (nb_bis >= 1) {
        len++;
        nb_bis /= 10;
    }
    while (nb >= 1) {
        str[len - 1] = nb % 10 + '0';
        i++;
        len--;
        nb /= 10;
    }
    str[i] = '\0';
    return str;
}
