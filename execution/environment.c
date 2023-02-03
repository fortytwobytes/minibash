/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:35 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 00:12:02 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	add_env(t_envs **envs, char *name, char *value)
{
	t_envs	*new;
	t_envs	*tmp;

	new = ft_calloc(sizeof(t_envs));
	new->name = ft_strdup(name);
	if (value == NULL)
		new->value = NULL;
	else
		new->value = ft_strdup(value);
	new->index = 0;
	new->next = NULL;
	if (!envs || !*envs)
	{
		*envs = new;
		return ;
	}
	tmp = *envs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	pop_env(char *name)
{
	t_envs	*tmp;
	t_envs	*prev;

	tmp = g_global.envs;
	prev = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			if (prev)
				prev->next = tmp->next;
			else
				g_global.envs = tmp->next;
			free(tmp->name);
			free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

t_envs	*envs_init(char **env)
{
	int		i;
	char	*name;
	char	*value;
	char	**sp;
	t_envs	*envs;

	i = 0;
	envs = NULL;
	while (env && env[i])
	{
		sp = ft_split(env[i], '=');
		name = sp[0];
		value = sp[1];
		add_env(&envs, name, value);
		free_split(sp);
		i++;
	}
	return (envs);
}

char	*ft_getenv(char *name)
{
	t_envs	*tmp;

	tmp = g_global.envs;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*get_env_value(char *name)
{
	t_envs	*tmp;

	tmp = g_global.envs;
	if (*name == '?')
		return (ft_itoa(g_global.exit_status));
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			if (tmp->value)
				return (tmp->value);
			return ("");
		}
		tmp = tmp->next;
	}
	return ("");
}
