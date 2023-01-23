#include "builtin.h"

static int  args_len(char **args);
char    *ft_getenv(char *name);

void    cd(char **args, int fd)
{
    int i = args_len(args);
    if (i == 1)
    {
        char *home = ft_getenv("HOME");
        if (!home)
            fatal("cd", "HOME not set", fd);
        else if (chdir(home) != 0)
            fatal("cd", "no such file or directory", fd);
    }
    else if (i >= 2)
    {
        if (chdir(args[1]))
            fatal("cd", "no such file or directory", fd);
    }
}

static int  args_len(char **args)
{
    int i = 0;
    while (args[i])
        i++;
    return (i);
}
