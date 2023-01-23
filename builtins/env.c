#include "builtin.h"

void    env(char **args)
{
    (void) args;
    int i = 0;
    for (t_envs *tmp = global.envs; tmp; tmp = tmp->next)
    {
        ft_putstr_fd(tmp->name, 1);
        ft_putchar_fd('=', 1);
        ft_putstr_fd(tmp->value, 1);
        ft_putchar_fd('\n', 1);
    }
}