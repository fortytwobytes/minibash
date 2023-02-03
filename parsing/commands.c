/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:44:16 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/01 00:00:03 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cat | ls | grep
// during exucution infile and outfile should be closee
// in the child and parent process
void	handle_pipes(t_cmd *cmd, t_token *tokens)
{
	if (tokens->type == PIPE)
		cmd->infile = tokens->pipe[READ_END];
	tokens = next_pipe(tokens);
	if (tokens)
		cmd->outfile = tokens->pipe[WRITE_END];
}

int	redirect(t_cmd *cmd, char *type, char *file)
{
	int	fd;

	if (!ft_strcmp(type, ">>"))
	{
		fd = ft_open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (fd == -1)
			return (0);
		cmd->outfile = fd;
	}
	if (!ft_strcmp(type, ">"))
	{
		fd = ft_open(file, O_CREAT | O_WRONLY, 0644);
		if (fd == -1)
			return (0);
		cmd->outfile = fd;
	}
	if (!ft_strcmp(type, "<"))
	{
		fd = ft_open(file, O_RDONLY, 0);
		if (fd == -1)
			return (0);
		cmd->infile = fd;
	}
	return (1);
}

// if a redirection fails we stop and don't execute the command
int	handle_redirection(t_cmd *cmd, t_token *tokens)
{
	int	status;

	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == REDIRECTION)
		{
			status = redirect(cmd, tokens->token, (tokens->next)->token);
			if (!status)
				return (status);
			tokens = tokens->next;
			tokens->type = FILE;
		}
		else if (tokens->type == HEREDOC)
		{
			tokens = tokens->next;
			status = handle_heredoc(cmd, tokens->token, here_doc_name());
			if (!status)
				return (status);
		}
		else
			tokens = tokens->next;
	}
	return (1);
}
// we check if fds are different to 0 because 
// by default they are initialized to 0 by calloc

void	handle_cmd(t_cmd *cmd, t_token *tokens)
{
	int		wc;
	int		i;
	char	**options;
	t_token	*head;

	wc = 0;
	head = tokens;
	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == WORD)
			wc++;
		tokens = tokens->next;
	}
	options = ft_calloc(sizeof(char *) * (wc + 1));
	i = 0;
	while (head && head->type != PIPE)
	{
		if (head->type == WORD)
			options[i++] = head->token;
		head = head->next;
	}
	cmd->args = options;
	cmd->cmd = options[0];
}

t_cmd	*convert_to_cmds(t_token *tokens)
{
	t_token	*head;
	t_cmd	*cmds;

	head = tokens;
	cmds = NULL;
	open_pipes(head);
	while (tokens)
		tokens = add_cmd(&cmds, tokens);
	return (cmds);
}
