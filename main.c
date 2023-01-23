#include "minishell.h"

t_global	global;

t_envs  *envs_init(void);
void	pop_env(char *name);
char	*ft_getenv(char *name);


int	main(int argc, char **argv, char **envp)
{
	global.env = envp;
	global.envs = envs_init();
	global.path = ft_getenv("PATH");	

	// when they run `bash -i ./minishell` or 'unset PATH'
	// we should hardcode some paths to make the same behavior as bash

	shell_loop();
	return (0);
}


