/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:13:52 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 07:06:18 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char		*get_name_(char *args);
char		*get_value_(int index, char *str);
static void	print_export(int fd);
static int	is_export_valid(char *envname);

void	export(char **args, int fd)
{
	char	*name;
	char	*value;
	int		idx;
	int		is_modified;

	if (*(args + 1) == NULL)
	{
		print_export(fd);
		return ;
	}
	args++;
	while (*args)
	{
		if ((idx = is_export_valid(*args) == -1))
		{
			fatal("export", "not a valid identifier");
			args++;
			continue ;
		}
		name = get_name_(*args);
		idx = ft_strlen(name);
		value = get_value_(idx, *args);
		if (*(*args + idx) == 0)
			is_modified = FALSE;
		else if (*(*args + idx) == '+')
			is_modified = is_updated(name, value, APPEND);
		else
			is_modified = is_updated(name, value, ADD);
		if (is_modified == FALSE)
			add_env(&g_global.envs, name, value);
		args++;
	}
	ft_putchar_fd(0, fd);
}

char	*get_name_(char *args)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = NULL;
	while (args[i])
	{
		if (args[i] == '=')
			break ;
		if (args[i] == '+' && args[i + 1] == '=')
			break ;
		i++;
	}
	buffer = ft_calloc(i + 1);
	ft_memcpy(buffer, args, i);
	return (buffer);
}

char	*get_value_(int index, char *str)
{
	int		len;
	char	*buffer;

	len = ft_strlen(str);
	if (str[index] == 0)
		return (NULL);
	if (str[index] == '+')
		index ++;
	else if (str[index + 1] == 0)
		return (ft_strdup(""));
	buffer = ft_calloc(len - index + 1);
	ft_memcpy(buffer, str + index + 1, len - index);
	return (buffer);
}

static void	print_export(int fd)
{
	int	size;

	size = size_of_env();
	index_envs();
	for (int counter = 0; counter < size; counter++)
	{
		for (t_envs *tmp = g_global.envs; tmp; tmp = tmp->next)
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
		}
	}
}

static int	is_export_valid(char *exp)
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
