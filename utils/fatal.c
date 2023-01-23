#include "utils.h"

void    fatal(char *cmd, char *msg, int fd)
{
    ft_putstr_fd("rmshell: ", fd);
    ft_putstr_fd(cmd, fd);
    ft_putstr_fd(": ", fd);
    ft_putstr_fd(msg, fd);
    ft_putchar_fd('\n', fd);
}