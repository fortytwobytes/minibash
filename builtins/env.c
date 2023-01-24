#include "builtin.h"

void	env(char **args, int fd)
{
	(void)args;
	int i = 0;
	char *value;
	for (t_envs *tmp = global.envs; tmp; tmp = tmp->next)
	{
		ft_putstr_fd(tmp->name, fd);
		ft_putchar_fd('=', fd);
		if (!ft_strcmp(tmp->name, "PWD"))
			ft_putstr_fd(global.pwd, fd);
		else if (!ft_strcmp(tmp->name, "SHLVL"))
			ft_putnbr_fd(global.shlvl, fd);
		else
			ft_putstr_fd(tmp->value, fd);
		ft_putchar_fd('\n', fd);
	}
}
