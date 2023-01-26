#include "srcs.h"

void	ft_execve(char *path, char **argv)
{
	if (execve(path, argv, dynamic_env()) == -1)
	{
		ft_putstr_fd("rmshell: ", STDERR_FILENO);
		ft_putstr_fd(argv[0], STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		exit(errno);
	}
}
