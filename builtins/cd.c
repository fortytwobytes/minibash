#include "builtin.h"

char		*ft_getenv(char *name);
static int	args_len(char **args);
static void	update_pwd(void);

void cd(char **args, int fd)
{
	int i = args_len(args);
	if (i == 1)
	{
		char *home = ft_getenv("HOME");
		if (!home)
			fatal("cd", "HOME not set", fd);
		else if (chdir(home) != 0)
			fatal("cd", "no such file or directory", fd);
	}
	else if (i >= 2)
	{
		if (chdir(args[1]))
			fatal("cd", "no such file or directory", fd);
	}
	update_pwd();
}

static int args_len(char **args)
{
	int i = 0;
	while (args[i])
		i++;
	return (i);
}

static void	update_pwd(void)
{
	char	*tmp;

	tmp = global.pwd;
	global.pwd = getcwd(NULL, 0);
	free(tmp);
}
