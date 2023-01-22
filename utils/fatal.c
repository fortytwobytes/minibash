#include "utils.h"

void    fatal(char *cmd, char *msg)
{
    ft_putstr_fd("rmshell: ", 2);
    ft_putstr_fd(cmd, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(msg, 2);
    ft_putchar_fd('\n', 2);
}