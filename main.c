#include "minishell.h"

t_global	global;
void	init_global(char **envp);


int	main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;
	
	init_global(envp);
	shell_loop();
	// parse_line("$@");
	// printf("%s",get_env_value("$HOME"));
	return (0);
}


void	init_global(char **envp)
{
	char	*tmp_shlvl;

	global.env = envp;
	global.exit_status = 0;
	global.pwd = getcwd(NULL, 0);
	global.envs = envs_init();
	global.path = ft_strdup("/bin/");
	tmp_shlvl = ft_getenv("SHLVL");
	if (!tmp_shlvl)
		global.shlvl = 1;
	else
		global.shlvl = ft_atoi(tmp_shlvl) + 1;
	// +1 because we are in a new shell level
	free(tmp_shlvl);
}
