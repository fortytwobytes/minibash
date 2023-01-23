#include "builtin.h"

static int  is_flag_n(char *flag); 
static void echo_args(int *n, char **args, int fd);

void    echo(char **args, int fd)
{
    int new_line = TRUE;
    int i = 1;

    if (args[i] == NULL)
    {
        ft_putstr_fd("\n", fd);
        return ;
    }
    if (is_flag_n(args[i]))
    {
        new_line = FALSE;
        i++;
    }
    echo_args(&new_line, args + i, fd);
    if (new_line == TRUE)
        ft_putstr_fd("\n", fd);
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

static void    echo_args(int *n, char **args, int fd)
{
    int i = 0;
    while (args && args[i])
    {
        ft_putstr_fd(args[i], fd);
        if (args[i + 1])
            ft_putchar_fd(' ', fd);
        i++;
    }
}
