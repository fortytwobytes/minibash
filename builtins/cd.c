#include "builtin.h"

static void	home_case(void);
static int	args_len(char **args);
static void	update_pwd(char *new_path);

void	cd(char **args, int fd)
{
	int		i;

	i = args_len(args);
	if (ft_getenv("OLDPWD") == NULL)
		add_env(&g_global.envs, ft_strdup("OLDPWD"), ft_strdup(""));
	if (i == 1)
		return (home_case(),
			ft_putchar_fd(0, fd), update_pwd(ft_getenv("HOME")));
	else
	{
		if (chdir(args[1]))
			fatal("cd", "no such file or directory");
	}
	ft_putchar_fd(0, fd);
	update_pwd(args[1]);
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

static void home_case(void)
{
	char	*home;

	home = ft_getenv("HOME");
	if (!home)
		return (fatal("cd", "HOME not set"));
	if (chdir(home) != 0)
		fatal("cd", "no such file or directory");
}