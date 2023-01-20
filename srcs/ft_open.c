#include "srcs.h"

int	ft_open(char *path, int flags, int mode)
{
	int	fd;

	fd = open(path, flags, mode); 
	if (fd == -1)
	{
		ft_putstr_fd("rmshell: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		exit(errno);
	}
	return (fd);
}
