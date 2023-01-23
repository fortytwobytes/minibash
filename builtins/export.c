#include "builtin.h"

void    add_env(t_envs **envs, char *env);

// here i would expect args as follows:
// args = {"export", "a=10", "b=30", ..., NULL};

void    export(char **args)
{
    if (*(args + 1) == NULL)
        return ;
    args++;
    while (*args)
    {
        add_env(&global.envs, *args);
        args++;
    }    
}