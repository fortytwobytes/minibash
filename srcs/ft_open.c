#include "srcs.h"

int	ft_open(char *path, int flags, int mode)
{
	int	fd;

	fd = open(path, flags, mode); 
	if (fd == -1)
		perror(path);
	return (fd);
}
