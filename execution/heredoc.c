/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:55 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 00:04:56 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*get_id(char *name);

char	*here_doc_name(void)
{
	char	*name;
	char	*tty_name;
	char	*id;

	tty_name = ttyname(0);
	id = get_id(tty_name);
	name = ft_strjoin("/tmp/.heredoc_", id);
	free(id);
	return (name);
}

static char	*get_id(char *name)
{
	char	*id;

	if (!name)
		return (NULL);
	while (*name && !is_num(*name))
		name++;
	id = name;
	return (ft_strdup(id));
}
