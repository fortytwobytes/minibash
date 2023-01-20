#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_main	main;

	main.argc = argc;
	main.argv = argv;
	main.envp = envp;
	// shell_loop(&main);
	parse_line(" echo     ");
	// system("leaks minishell");
	return (0);
}
