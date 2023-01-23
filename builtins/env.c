#include "builtin.h"

void    env(char **args, int fd)
{
    (void) args;
    int i = 0;
    for (t_envs *tmp = global.envs; tmp; tmp = tmp->next)
    {
        ft_putstr_fd(tmp->name, fd);
        ft_putchar_fd('=', fd);
        ft_putstr_fd(tmp->value, fd);
        ft_putchar_fd('\n', fd);
    }
}