#include "minishell.h"

// here are some useful debuggin functions that can be deleted later
// NOTE! you should condider adding debbugin.c next to main.c in your MAKEFILE

void	print_global(char *path, char *env, char *our_env);


// this function gets 3 arguments: path, sysenv, our_env
// if you want to print any of them, just pass the name of the variable as an argument
// else pass NULL
// example: print_global("PATH", NULL, NULL);
void	print_global(char *path, char *env, char *our_env)
{
    if (our_env)
    {
        printf("----------%s----------\n", our_env);
    	for (t_envs *tmp = global.envs; tmp; tmp = tmp->next)
		    printf("{\n\tname: \"%s\",\n\tvalue: \"%s\"\n},\n", tmp->name, tmp->value);
    }
    if (path)
    {
        printf("-----------%s---------\n", path);
        printf("PATH: %s\n", global.path);
    }
    if (env)
    {
        printf("----------%s----------\n", env);
        for (int i = 0; global.env[i]; i++)
            printf("env[%d]: %s\n", i, global.env[i]);
    }
}

// hardcode builtins for quick testing
void	hardcode_builtins(char **args, int outfile)
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
		exit(EXIT_SUCCESS);
}

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