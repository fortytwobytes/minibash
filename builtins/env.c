#include "builtin.h"

void	env(char **args, int fd)
{
	(void)args;
	for (t_envs *tmp = global.envs; tmp; tmp = tmp->next)
	{

		ft_putstr_fd(tmp->name, fd);
		ft_putchar_fd('=', fd);
		if (!ft_strcmp(tmp->name, "PWD"))
			ft_putstr_fd(global.pwd, fd);
		else
			ft_putstr_fd(tmp->value, fd);
		ft_putchar_fd('\n', fd);
	}
}
