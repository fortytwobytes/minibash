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

// should print if a valid identifier : bash: unset:
// `/Users/mtagemou': not a valid identifier
static int	unset_regex(char c);

int	unset(char **args, int fd)
{
	if (*(args + 1) == NULL)
		return (0);
	args++;
	while (*args)
	{
		if (unset_regex(*(*args)))
		{
			fatal("unset", "invalid identifier");
			return (1);
		}
		if (!ft_strcmp(*args, "_"))
			continue ;
		pop_env(*args);
		args++;
	}
	ft_putchar_fd(0, fd);
	return (0);
}

static int	unset_regex(char c)
{
	return (!is_upper(c) && !is_lower(c) && c != '_');
}
