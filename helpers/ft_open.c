/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:33:31 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:34:02 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int	ft_open(char *path, int flags, int mode)
{
	int	fd;

	fd = open(path, flags, mode);
	if (fd == -1)
		perror(path);
	return (fd);
}
