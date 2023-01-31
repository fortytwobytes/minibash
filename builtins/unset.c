#include "builtin.h"

// should print if a valid identifier : bash: unset: `/Users/mtagemou': not a valid identifier
void	unset(char **args, int fd)
{
	if (*(args + 1) == NULL)
		return ;
	args++;
	while (*args)
	{
		if (!ft_strcmp(*args, "_"))
			continue ;
		pop_env(*args);
		args++;
	}
	ft_putchar_fd(0, fd);
}
