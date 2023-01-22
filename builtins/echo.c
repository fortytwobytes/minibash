#include "builtin.h"

static int  is_flag_n(char *flag); 
static void echo_args(int *n, char **args);

void    echo(char **args)
{
    int new_line = TRUE;
    int i = 1;

    if (args[i] == NULL)
    {
        ft_putstr_fd("\n", 1);
        return ;
    }
    if (is_flag_n(args[i]))
    {
        new_line = FALSE;
        i++;
    }
    echo_args(&new_line, args + i);
    if (new_line == TRUE)
        ft_putstr_fd("\n", 1);
}

static int  is_flag_n(char *flag)
{
    int i = 0;
    if (!ft_strcmp(flag, "-n"))
        return (TRUE);
    if (flag[0] != '-')
        return (FALSE);
    i++;
    while (flag && flag[i])
    {
        if (flag[i] != 'n')
            return (FALSE);
        i++;
    }
    return (TRUE);
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
