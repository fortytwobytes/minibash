#include "builtin.h"

void    pwd(char **args)
{
    char *cwd;

    (void) args;
    cwd = getcwd(NULL, 0);
    if (!cwd)
        fatal("pwd", strerror(errno));
    ft_putstr_fd(cwd, 1);
    ft_putchar_fd('\n', 1);
    free(cwd);
}