#include "srcs.h"

void ft_pipe(int fd[2])
{
	if (pipe(fd) == -1)
		ft_exit(errno, strerror(errno));
}
