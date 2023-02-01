/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:00:55 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 00:02:10 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// free(head->cmd);
// free(head->path);
void	free_cmd(t_cmd *head)
{
	t_cmd	*tmp;

	while (head)
	{
		free_split(head->args);
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void	close_fds(t_cmd *cmd)
{
	if (cmd->infile != 0)
		close(cmd->infile);
	if (cmd->outfile != 0)
		close(cmd->outfile);
}

t_token	*add_cmd(t_cmd **cmds, t_token *tokens)
{
	t_cmd	*new;
	t_cmd	*last;
	int		status;

	last = *cmds;
	new = ft_calloc(sizeof(t_cmd));
	handle_pipes(new, tokens);
	if (tokens->type == PIPE)
		tokens = tokens->next;
	status = handle_redirection(new, tokens);
	if (!status)
	{
		close_fds(new);
		free(new);
		perror("");
		return (next_pipe(tokens));
	}
	handle_cmd(new, tokens);
	if (!last)
	{
		*cmds = new;
		return (next_pipe(tokens));
	}
	while (last->next)
		last = last->next;
	last->next = new;
	return (next_pipe(tokens));
}
