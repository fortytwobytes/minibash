#include "builtin.h"

void    pwd(char **args, int fd)
{
    char *cwd;

    (void) args;
    cwd = getcwd(NULL, 0);
    if (!cwd)
        fatal("pwd", strerror(errno), fd);
    ft_putstr_fd(cwd, fd);
    ft_putchar_fd('\n', fd);
    free(cwd);
}