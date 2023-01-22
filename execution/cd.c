#include "builtin.h"

static int  args_len(char **args);

void    cd(char **args)
{
    int i = args_len(args);
    if (i > 2)
        fatal("cd", "too many arguments");
    else if (i == 1)
    {
        if (chdir(getenv("HOME")) != 0)
            fatal("cd", "no such file or directory");
    }
    else if (i == 2)
    {
        if (chdir(args[1]) != 0)
            fatal("cd", "no such file or directory");
    }
}


static int  args_len(char **args)
{
    int i = 0;
    while (args[i])
        i++;
    return (i);
}