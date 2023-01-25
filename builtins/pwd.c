#include "builtin.h"

void	pwd(char **args, int fd)
{
	char *cwd;

	(void) args;
	ft_putstr_fd(global.pwd, fd);
	ft_putchar_fd('\n', fd);
}
