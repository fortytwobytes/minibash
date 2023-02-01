#include "builtin.h"

void	env(char **args, int fd)
{
	t_envs	*tmp;

	(void) args;
	tmp = global.envs;
	while (tmp)
	{
		if (tmp->value == NULL)
		{
			tmp = tmp->next;
			continue ;
		}
		ft_putstr_fd(tmp->name, fd);
		ft_putchar_fd('=', fd);
		ft_putstr_fd(tmp->value, fd);
		ft_putchar_fd('\n', fd);
		tmp = tmp->next;
	}
}
