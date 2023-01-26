#include "srcs.h"

int	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("");
	return (pid);
}
