/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:46 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 00:04:47 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// |>


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
			continue;
		}
		ignore_signals();
		execute(cmd);
		free(line);
	}
}
