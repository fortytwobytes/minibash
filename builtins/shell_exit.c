#include "minishell.h"

int is_all_num(char *s)
{
	while(*s)
	{
		if (!is_num(*s))
			return (0);
		s++;
	}
	return 1;
}

// If n is omitted, the exit status is that of the last command executed
void shell_exit(char **args)
{
	ft_putstr_fd("exit\n",2);
	if (args[1] == NULL)
		exit(global.exit_status);
	if (is_all_num(args[1]))
	{
		if (args[2] == NULL)
			exit(ft_atoi(args[0]));
		else
		{
			ft_putstr_fd("too many arguments\n",2);
			return;
		}
	}
	else
	{
		ft_putstr_fd("numeric argument required\n",2);
		exit(255);
	}
}