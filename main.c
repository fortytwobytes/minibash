#include "minishell.h"

t_global	global;
void	init_global(char **envp);


int	main(int argc, char **argv, char **envp)
{
	// first we need to search inside the ft_getenv() if NULL
	// we test the hardcoded PATH if not we print fatal

	// when they run `bash -i ./minishell` or 'unset PATH'
	// we should hardcode some paths to make the same behavior as bash
	init_global(envp);

	shell_loop();
	// parse_line("$HOME");
	// printf("%s",get_env_value("$HOME"));
	return (0);
}


void	init_global(char **envp)
{
	char	*tmp_shlvl;

	global.env = envp;
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
