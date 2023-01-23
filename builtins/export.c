#include "builtin.h"

void    add_env(t_envs **envs, char *env);

// here i would expect args as follows:
// args = {"export", "a=10", "b=30", ..., NULL};

void    export(char **args, int fd)
{
    if (*(args + 1) == NULL)
        return ;
    args++;
    while (*args)
    {
        add_env(&global.envs, *args);
        args++;
    }
    ft_putchar_fd(0, fd);
}