#include "builtin.h"

void	pwd(char **args, int fd)
{
	(void) args;

	char	*pwdir;

	pwdir = ft_getenv("PWD");
	ft_putstr_fd(pwdir, fd);
	ft_putchar_fd('\n', fd);
}
