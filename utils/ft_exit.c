#include "utils.h"

void	ft_exit(char *msg, int status)
{
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n", 2);
	}
	exit(status); // maybe this can cause memory leak
}
