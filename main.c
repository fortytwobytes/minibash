/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:44:18 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/01 21:44:20 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minibash.h"

t_global	g_global;
void	init_global(char **envp);

int	main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;
	rl_catch_signals = 0;
	init_global(envp);
	shell_loop();
	return (0);
}

void	init_global(char **envp)
{
	char	*tmp_shlvl;
	char	*tmp_path;

	g_global.heredoc_flag = 0;
	g_global.exit_status = 0;
	g_global.envs = envs_init(envp);
	tmp_path = ft_getenv("PATH");
	if (!tmp_path)
		add_env(&g_global.envs, "PATH", "/bin/");
	tmp_shlvl = ft_getenv("SHLVL");
	if (!tmp_shlvl)
		add_env(&g_global.envs, "SHLVL", "1");
	else
		ft_setenv("SHLVL", ft_itoa(ft_atoi(tmp_shlvl) + 1));
}
