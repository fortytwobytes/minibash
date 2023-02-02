/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:09:34 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 23:09:35 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	env(char **args, int fd)
{
	t_envs	*tmp;

	(void) args;
	tmp = g_global.envs;
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
