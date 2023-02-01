/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:03:18 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 23:44:01 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	is_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

int	exec_builtins(char **args, int outfile)
{
	if (!ft_strcmp(args[0], "cd"))
		cd(args, outfile);
	if (!ft_strcmp(args[0], "pwd"))
		pwd(args, outfile);
	if (!ft_strcmp(args[0], "echo"))
		echo(args, outfile);
	if (!ft_strcmp(args[0], "export"))
		export(args, outfile);
	if (!ft_strcmp(args[0], "unset"))
		unset(args, outfile);
	if (!ft_strcmp(args[0], "env"))
		env(args, outfile);
	if (!ft_strcmp(args[0], "exit"))
		shell_exit(args);
	return (1111111);
}

void	index_envs(void)
{
	t_envs	*tmp;
	t_envs	*tmp1;

	tmp = global.envs;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	tmp = global.envs;
	while (tmp)
	{
		tmp1 = global.envs;
		while (tmp1)
		{
			if (ft_strcmp(tmp->name, tmp1->name) > 0)
				tmp->index++;
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

int	size_of_env(void)
{
	int		i;
	t_envs	*tmp;

	i = 0;
	tmp = global.envs;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_export_valid(char *exp)
{
	int	i;

	i = 0;
	if (!is_lower(*exp) && !is_upper(*exp) && *exp != '_')
		return (-1);
	while (exp[i])
	{
		if (exp[i] == '=')
			return (i + 1);
		if (exp[i] == '+' && exp[i + 1] == '=')
			return (i + 2);
		i++;
	}
	return (i);
}
