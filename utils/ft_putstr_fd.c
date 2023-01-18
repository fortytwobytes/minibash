#include "utils.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		ft_putstr_fd("(null)", fd);
	else if (s)
		write(fd, s, ft_strlen(s));
}
