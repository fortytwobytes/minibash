/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:10:11 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 23:10:27 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	pwd(char **args, int fd)
{
	char	*pwdir;

	(void) args;
	pwdir = ft_getenv("PWD");
	if (pwdir == NULL)
	{
		pwdir = getcwd(NULL, 0);
		if (pwdir == NULL)
			fatal("pwd", "error retrieving current directory");
		else
			ft_putstr_fd(pwdir, fd);
		free(pwdir);
	}
	else
		ft_putstr_fd(pwdir, fd);
	ft_putchar_fd('\n', fd);
}
