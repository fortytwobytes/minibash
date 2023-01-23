#include "builtin.h"

void    pop_env(char *name);

void    unset(char **args)
{
    if (*(args + 1) == NULL)
        return ;
    args++;
    while (*args)
    {
        pop_env(*args);
        args++;
    }
}