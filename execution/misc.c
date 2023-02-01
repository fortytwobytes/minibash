/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:05:40 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 07:04:07 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	command_not_found(void)
{
	write(2, "command not found\n", 19);
	exit(127);
}

int	is_updated(char *name, char *value, int option)
{
	t_envs	*tmp;
	char	*holder;

	tmp =g_global.envs;
	if (value == NULL)
		return (FALSE);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			holder = tmp->value;
			if (option == ADD)
				tmp->value = ft_strdup(value);
			else if (option == APPEND)
				tmp->value = ft_strjoin(holder, value);
			free(holder);
			return (TRUE);
		}
		tmp = tmp->next;
	}
	return (FALSE);
}

char	**dynamic_env(void)
{
	int		i;
	int		j;
	char	**env;
	t_envs	*tmp;

	i = 0;
	tmp =g_global.envs;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	env = ft_calloc(sizeof(char *) * (i + 1));
	j = 0;
	tmp =g_global.envs;
	while (j < i)
	{
		if (tmp->value == NULL)
			tmp->value = "";
		env[j] = ft_strjoin_sep(tmp->name, tmp->value, '=');
		tmp = tmp->next;
		j++;
	}
	return (env);
}

void	ft_setenv(char *name, char *value)
{
	t_envs	*tmp;

	tmp =g_global.envs;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			free(tmp->value);
			tmp->value = value;
			return ;
		}
		tmp = tmp->next;
	}
}

void	update_env(char *name, char *value)
{
	t_envs *tmp;
	char *holder;

	tmp =g_global.envs;
	if (!name || !value)
		return;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			holder = tmp->value;
			tmp->value = ft_strdup(value);
			free(holder);
			return;
		}
		tmp = tmp->next;
	}
}