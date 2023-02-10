/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:46 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/10 12:27:49 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_space(char c);
static void	ft_add_history(char *line);

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
		ft_add_history(line);
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

static void	ft_add_history(char *line)
{
	char	*ptr;

	ptr = line;
	if (!line)
		return ;
	while (*line && is_space(*line))
	{
		line++;
	}
	if (*line != 0)
		add_history(ptr);
}

static int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
