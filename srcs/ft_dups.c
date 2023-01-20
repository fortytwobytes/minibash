#include "srcs.h"

void	ft_dup(int fd)
{
	if (dup(fd) == -1)
		ft_exit(errno, strerror(errno));
}

void	ft_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
		ft_exit(errno, strerror(errno));
}
