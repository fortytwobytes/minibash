#include "minishell.h"

t_global	global;
void	init_global(char **envp);


int	main(int argc, char **argv, char *envp[])
{
	// first we need to search inside the ft_getenv() if NULL
	// we test the hardcoded PATH if not we print fatal

	// when they run `bash -i ./minishell` or 'unset PATH'
	// we should hardcode some paths to make the same behavior as bash
	init_global(envp);
	shell_loop();
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
		add_env(&global.envs,ft_strdup("SHLVL"),ft_strdup("1"));
	else
		ft_setenv("SHLVL" , ft_itoa(ft_atoi(tmp_shlvl) + 1));
}
