/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtagemou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 20:12:46 by mtagemou          #+#    #+#             */
/*   Updated: 2023/01/29 20:12:47 by mtagemou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_num_of_characters(int n, int *signe)
{
	int	num_of_characters;

	num_of_characters = 2;
	while (n / 10)
	{
		num_of_characters ++;
		n /= 10;
	}
	*signe = 1;
	if (n < 0)
	{
		*signe = -1;
		num_of_characters++;
	}
	return (num_of_characters);
}

char	*ft_itoa(int n)
{
	int		num_of_characters;
	int		signe;
	char	*sol;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_of_characters = ft_num_of_characters(n, &signe);
	if (signe == -1)
		n *= -1;
	sol = ft_calloc(num_of_characters);
	--num_of_characters;
	while (n / 10)
	{
		sol[--num_of_characters] = n % 10 + '0';
		n /= 10;
	}
	sol[--num_of_characters] = n % 10 + '0';
	if (num_of_characters == 1)
		sol[0] = '-';
	return (sol);
}
