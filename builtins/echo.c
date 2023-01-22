#include "builtin.h"

static void echo_args(int *n, char **args);

void    echo(char **args)
{
    int new_line = TRUE;
    int i = 1;

    if (!ft_strcmp(args[1], "-n"))
    {
        new_line = FALSE;
        i++;
    }
    echo_args(&new_line, args + i);
    if (new_line == TRUE)
        ft_putstr_fd("\n", 1);
}

static void    echo_args(int *n, char **args)
{
    int i = 0;
    while (args && args[i])
    {
        ft_putstr_fd(args[i], 1);
        if (args[i + 1])
            ft_putchar_fd(' ', 1);
        i++;
    }
}
