/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:19:08 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:19:09 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	index;

	index = -1;
	if (dst == src || !n)
		return (dst);
	while (++index < n)
		*(char *)(dst + index) = *(char *)(src + index);
	return (dst);
}
