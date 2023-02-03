/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:44:41 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 19:44:43 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_env_name(char c)
{
	if (is_lower(c) || is_upper(c) || is_num(c) || c == '_')
		return (1);
	return (0);
}

int	handle_heredocs(t_cmd *cmd, t_token *tokens)
{
	int	status;

	while (tokens && tokens->type != PIPE)
	{
		if (tokens->type == HEREDOC)
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
