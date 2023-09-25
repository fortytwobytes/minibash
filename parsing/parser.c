/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:44:31 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/31 23:50:55 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// this function checks if we have another type of operator except the ones
// handled by our minishell
int	check_invalid_operator(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == OPERATOR)
			return (0);
		tokens = tokens->next;
	}
	return (1);
}

// this one checks if every redirection token is followed by a word
int	check_redirections(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == REDIRECTION || tokens->type == HEREDOC)
		{
			if (tokens->next)
			{
				if ((tokens->next)->type != WORD)
					return (0);
			}
			else
				return (0);
		}
		tokens = tokens->next;
	}
	return (1);
}

// this functions checks if there is a word after a pipe before
// the appearance of another pipe
// word | word => valid
// word | | word => invalid
int	word_after(t_token *tokens)
{
	tokens = tokens->next;
	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == WORD)
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

// this function checks if every pipe is preceded by a word AND
// followed by a word
int	check_pipes(t_token *tokens)
{
	int	word_before;

	word_before = 0;
	while (tokens)
	{
		if (tokens->type == WORD)
			word_before = 1;
		if (tokens->type == PIPE)
		{
			if (!word_before || !word_after(tokens))
				return (0);
			word_before = 0;
		}
		tokens = tokens->next;
	}
	return (1);
}

// this function returns 1 if the parsing is correct and -1 if incorrct
int	parse(t_token *tokens)
{
	if (!check_invalid_operator(tokens))
		return (0);
	if (!check_redirections(tokens))
		return (0);
	if (!check_pipes(tokens))
		return (0);
	return (1);
}
