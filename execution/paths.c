/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 00:04:43 by relkabou          #+#    #+#             */
/*   Updated: 2023/02/01 15:09:58 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*ft_getpath(char *cmd)
{
	int		i;
	char	*tmp;
	char	*paths;
	char	**sp_paths;

	i = -1;
	if (is_char_in_str(cmd, '/'))
		return (ft_strdup(cmd));
	paths = ft_getenv("PATH");
	if (!paths)
		return (NULL);
	sp_paths = ft_split(paths, ':');
	while (sp_paths[++i])
	{
		tmp = ft_strjoin_sep(sp_paths[i], cmd, '/');
		if (access(tmp, X_OK) == -1)
			free(tmp);
		else
			return (free_split(sp_paths), tmp);
	}
	free_split(sp_paths);
	return (NULL);
}

int	is_char_in_str(char *str, char c)
{
	while (str && *str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}
