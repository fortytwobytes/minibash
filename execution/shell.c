/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:46 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:03 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(void)
{
	char	*line;
	t_cmd	*cmd;

	while (TRUE)
	{
		handle_signals();
		line = readline(PROMPT);
		if (!line)
			break ;
		add_history(line);
		cmd = parse_line(line);
		if (g_global.heredoc_flag)
		{
			g_global.heredoc_flag = 0;
			close_all_fds(cmd);
			free_cmd(cmd);
			free(line);
			continue ;
		}
		ignore_signals();
		execute(cmd);
		free(line);
	}
}

void	set_exit_status(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', 1);
}
