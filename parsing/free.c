/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:49:02 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:49:33 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token *tokens)
{	
	t_token	*prev;

	while (tokens)
	{
		prev = tokens;
		if (prev->type != WORD && prev->type != LIMITER)
			free(tokens->token);
		tokens = tokens->next;
		free(prev);
	}
}

void	free_all(t_token *tokens)
{
	t_token	*prev;

	while (tokens)
	{
		prev = tokens;
		free(tokens->token);
		tokens = tokens->next;
		free(prev);
	}
}
