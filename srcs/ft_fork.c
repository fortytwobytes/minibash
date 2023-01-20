#include "srcs.h"

int	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(errno, strerror(errno));
	return (pid);
}
