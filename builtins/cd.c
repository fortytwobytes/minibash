/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:08:50 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 23:08:53 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	home_case(void);
static int	args_len(char **args);
static void	update_pwd(char *new_path);

int	cd(char **args, int fd)
{
	int		i;
	int exit_status;

	i = args_len(args);
	if (i == 1)
	{
		exit_status = home_case();
		ft_putchar_fd(0, fd); 
		update_pwd(ft_getenv("HOME"));
		return exit_status;
	}
	else
	{
		if (chdir(args[1]))
		{
			fatal("cd", "no such file or directory");
			return (1);
		}
	}
	ft_putchar_fd(0, fd);
	update_pwd(args[1]);
	return (0);
}

static int	args_len(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static void	update_pwd(char *new_path)
{
	char	*new_wd;

	update_env("OLDPWD", ft_getenv("PWD"));
	new_wd = getcwd(NULL, 0);
	if (new_wd == NULL)
	{
		new_wd = ft_strjoin_sep(ft_getenv("OLDPWD"), new_path, '/');
		update_env("PWD", new_wd);
		fatal("cd", "error retrieving current directory");
	}
	else
		update_env("PWD", new_wd);
	free(new_wd);
}

static int	home_case(void)
{
	char	*home;

	home = ft_getenv("HOME");
	if (!home)
	{
		fatal("cd", "HOME not set");
		return (1);
	}
	if (chdir(home) != 0)
	{
		fatal("cd", "no such file or directory");
		return (1);
	}
	return (0);
}
