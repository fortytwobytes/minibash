#include "minishell.h"

t_global	global;
void	init_global(char **envp);

int	main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;

	init_global(envp);
	handle_signals();
	shell_loop();
	return (0);
}

void	init_global(char **envp)
{
	char	*tmp_shlvl;

	global.exit_status = 0;
	global.envs = envs_init(envp);
	tmp_shlvl = ft_getenv("SHLVL");
	if (!tmp_shlvl)
		add_env(&global.envs, ft_strdup("SHLVL"), ft_strdup("1"));
	else
		ft_setenv("SHLVL", ft_itoa(ft_atoi(tmp_shlvl) + 1));
}
