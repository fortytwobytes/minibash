/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:47 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 23:11:15 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// should print if a valid identifier : bash: unset:
// `/Users/mtagemou': not a valid identifier
void	unset(char **args, int fd)
{
	if (*(args + 1) == NULL)
		return ;
	args++;
	while (*args)
	{
		if (!ft_strcmp(*args, "_"))
			continue ;
		pop_env(*args);
		args++;
	}
	ft_putchar_fd(0, fd);
}
