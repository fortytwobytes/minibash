/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:55 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 05:21:21 by relkabou         ###   ########.fr       */
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
	char		*id;
	static int	i; 
	char		*id2;

	if (!name)
		return (NULL);
	while (*name && !is_num(*name))
		name++;
	id2 = ft_itoa(i++);
	id = ft_strjoin_sep(name, id2, '_');
	free(id2);
	return (id);
}
