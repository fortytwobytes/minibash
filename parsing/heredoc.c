/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:50:04 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/01 21:50:05 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_expand(char **limiter)
{
	if (contains(*limiter, '"') || contains(*limiter, '\''))
	{
		*limiter = quotes_removal(*limiter);
		return (0);
	}
	return (1);
}

int	handle_heredoc(t_cmd *cmd, char *limiter, char *file)
{
	int		expand_mode;
	char	*line;
	char	*joined_line;
	int		fd;

	expand_mode = is_expand(&limiter);
	fd = ft_open(file, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (0);
	line = readline("> ");
	while (ft_strcmp(line, limiter))
	{
		if (!line)
			break ;
		if (expand_mode && *line)
			line = parameter_expansion(line);
		joined_line = ft_strjoin(line, "\n");
		write(fd, joined_line, ft_strlen(joined_line));
		free(line);
		free(joined_line);
		line = readline("> ");
	}
	free(line);
	close(fd);
	fd = open(file, O_RDONLY, 0);
	if (fd == -1)
		return (0);
	cmd->infile = fd;
	free(file);
	return (1);
}
