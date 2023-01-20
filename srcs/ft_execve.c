#include "srcs.h"

void	ft_execve(char *path, char **argv, char **envp)
{
	if (execve(path, argv, envp) == -1)
		ft_exit(errno, strerror(errno));
}
