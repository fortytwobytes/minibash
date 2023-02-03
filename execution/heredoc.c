/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:55 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/03 14:51:10 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*get_id(char *name);

char	*here_doc_name(void)
{
	char	*name;
	char	*tty_name;

	tty_name = ttyname(0);
	name = get_id(tty_name);
	return (name);
}

static char	*get_id(char *name)
{
	char		*id;
	static int	i;
	char		*id2;
	char		*tmp;

	if (!name)
		return (NULL);
	while (*name && !is_num(*name))
		name++;
	while (TRUE)
	{
		id2 = ft_itoa(i);
		tmp = ft_strjoin_sep(name, id2, '_');
		id = ft_strjoin("/tmp/.heredoc_", tmp);
		free(id2);
		free(tmp);
		i++;
		if (access(id, F_OK) == -1)
			break ;
		free(id);
	}
	return (id);
}
