#include "builtin.h"

int	is_builtins(char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		return 1;
	if (!ft_strcmp(cmd, "pwd"))
		return 1;
	if (!ft_strcmp(cmd, "echo"))
		return 1;
	if (!ft_strcmp(cmd, "export"))
		return 1;
	if (!ft_strcmp(cmd, "unset"))
		return 1;
	if (!ft_strcmp(cmd, "env"))
		return 1;
	if (!ft_strcmp(cmd, "exit"))
		return 1;
	return  0;
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
		shell_exit(EXIT_SUCCESS);
	return (111111);
}

