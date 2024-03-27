/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:01:35 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 20:01:37 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minibash.h"

int	is_all_num(char *s)
{
	while (*s)
	{
		if (!is_num(*s))
			return (0);
		s++;
	}
	return (1);
}

// If n is omitted, the exit status is that of the last command executed
int	shell_exit(char **args)
{
	ft_putstr_fd("exit\n", 2);
	if (args[1] == NULL)
		exit(g_global.exit_status);
	if (is_all_num(args[1]))
	{
		if (args[2] == NULL)
			exit(ft_atoi(args[1]));
		else
		{
			ft_putstr_fd("too many arguments\n", 2);
			return (1);
		}
	}
	else
	{
		ft_putstr_fd("numeric argument required\n", 2);
		exit(255);
	}
	return (0);
}
