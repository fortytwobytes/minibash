#include "minishell.h"

// here are some useful debuggin functions that can be deleted later
// NOTE! you should condider adding debbugin.c next to main.c in your MAKEFILE

void	print_global(char *path, char *env, char *our_env);
void    hardcode_builtins(char **args);


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
void	hardcode_builtins(char **args)
{
	if (*args == NULL)
		return ;
	if (!ft_strcmp(args[0], "cd"))
		cd(args, 1);
	if (!ft_strcmp(args[0], "pwd"))
		pwd(args, 1);
	if (!ft_strcmp(args[0], "echo"))
		echo(args, 1);
	if (!ft_strcmp(args[0], "export"))
		export(args, 1);
	if (!ft_strcmp(args[0], "unset"))
		unset(args, 1);
	if (!ft_strcmp(args[0], "env"))
		env(args, 1);
	if (!ft_strcmp(args[0], "./minishell")) // this case should be added
	{
		global.shlvl++;
		// for dubshells
		shell_loop();
		// we should execute minishell as a normal command here
	}
	if (!ft_strcmp(args[0], "exit"))
	{
		free_split(args);
		global.shlvl--;
		exit(EXIT_SUCCESS);
		// exit should behave like ctrl + d
		// if we are in a subshell we should exit the subshell
		// not the whole program
	}
}
