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

void add(t_cmd **cmds,t_cmd *new)
{
	t_cmd *last;

	last = *cmds;
	if (!last)
		*cmds = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}
t_token *free_cmds(t_cmd *new ,t_token *tokens)
{
	t_token *tmp;
	

	free(new);
	if (!tokens)
		return NULL;
	if (tokens->type == PIPE)
		tokens = tokens->next;
	while (tokens && tokens->type != PIPE)
	{
		tmp = tokens;
		tokens = tokens->next;
		if (tmp->type == WORD)
			free(tmp->token);
	}
	return (tokens);
}

t_token	*add_cmd(t_cmd **cmds, t_token *tokens)
{
	t_cmd	*new;
	int		status;

	new = ft_calloc(sizeof(t_cmd));
	handle_pipes(new, tokens);
	if (tokens->type == PIPE)
		tokens = tokens->next;
	status = handle_redirection(new, tokens);
	if (!status)
	{
		close_fds(new);
		g_global.exit_status = 1;
		return (free_cmds(new,tokens));
	}
	handle_cmd(new, tokens);
	add(cmds,new);
	return (next_pipe(tokens));
}