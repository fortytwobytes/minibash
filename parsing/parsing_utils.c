/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:55:05 by mtagemou          #+#    #+#             */
/*   Updated: 2023/02/03 14:55:07 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_pipes(t_token	*tokens)
{
	while (tokens)
	{
		if (tokens->type == PIPE)
			ft_pipe(tokens->pipe);
		tokens = tokens->next;
	}
}

t_token	*next_pipe(t_token *tokens)
{
	if (!tokens)
		return (NULL);
	if (tokens->type == PIPE)
		tokens = tokens->next;
	while (tokens && tokens->type != PIPE)
		tokens = tokens->next;
	return (tokens);
}

// in this function we remplace the -1 occurences with $
// i need dollars dollars dollars is what i need
void	expands_dollars_dollars(char *token)
{
	while (*token)
	{
		if (*token == -1)
			*token = '$';
		token++;
	}
}

void	free_token_word(t_token *token, char *word)
{
	free(word);
	free(token);
}
