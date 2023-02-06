/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:47 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/03 14:24:35 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	unset_regex(char *s);

int	unset(char **args, int fd)
{
	if (*(args + 1) == NULL)
		return (0);
	args++;
	while (*args)
	{
		if (unset_regex(*args))
		{
			fatal("unset", "invalid identifier");
			return (1);
		}
		pop_env(*args);
		args++;
	}
	ft_putchar_fd(0, fd);
	return (0);
}

static int	unset_regex(char *s)
{
	if (!is_lower(*s) && !is_upper(*s) && *s != '_')
		return (1);
	s++;
	while (*s)
	{
		if (!is_env_name(*s))
			return (1);
		s++;
	}
	return (0);
}
