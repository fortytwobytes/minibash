#include "srcs.h"

void	ft_close(int fd)
{
	if (close(fd) == -1)
		ft_exit(errno, strerror(errno));
}
