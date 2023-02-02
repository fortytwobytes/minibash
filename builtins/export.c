/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:13:52 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/02 00:07:41 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	print_export(int fd);
static void	export_conditions(int idx, char *arg);
static void	print_export_helper(int fd, int counter);

int	export(char **args, int fd)
{
	int	idx;
	int exit_status;

	exit_status = 1;
	if (*(args + 1) == NULL)
		return (print_export(fd));
	args++;
	while (*args)
	{
		idx = is_export_valid(*args);
		if (idx == -1)
		{
			fatal("export", "not a valid identifier");
			args++;
			continue ;
		}
		exit_status = 0;
		export_conditions(idx, *args);
		args++;
	}
	ft_putchar_fd(0, fd);
	return exit_status;
}

static void	export_conditions(int idx, char *arg)
{
	char	*name;
	char	*value;
	int		is_modified;

	name = get_name_(arg);
	idx = ft_strlen(name);
	value = get_value_(idx, arg);
	if (*(arg + idx) == 0)
		is_modified = FALSE;
	else if (*(arg + idx) == '+')
		is_modified = is_updated(name, value, APPEND);
	else
		is_modified = is_updated(name, value, ADD);
	if (is_modified == FALSE)
		add_env(& g_global.envs, name, value);
	free(name);
	free(value);
}

static void	print_export_helper(int fd, int counter)
{
	t_envs	*tmp;

	tmp = g_global.envs;
	while (tmp)
	{
		if (counter == tmp->index)
		{
			if (!ft_strcmp(tmp->name, "_"))
				break ;
			ft_putstr_fd("declare -x ", fd);
			ft_putstr_fd(tmp->name, fd);
			if (tmp->value != NULL)
			{
				ft_putchar_fd('=', fd);
				ft_putchar_fd('\"', fd);
				ft_putstr_fd(tmp->value, fd);
				ft_putchar_fd('\"', fd);
			}
			ft_putchar_fd('\n', fd);
			break ;
		}
		tmp = tmp->next;
	}
}

static int	print_export(int fd)
{
	int	size;
	int	counter;

	counter = 0;
	size = size_of_env();
	index_envs();
	while (counter < size)
	{
		print_export_helper(fd, counter);
		counter++;
	}
	return (0);
}
