/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relkabou <relkabou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:18:57 by relkabou          #+#    #+#             */
/*   Updated: 2023/01/31 23:18:58 by relkabou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	put_nbr_base(unsigned long nbr, char *base, int base_len, int fd);

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		ft_putstr_fd("(null)", fd);
	else
		while (*s)
			ft_putchar_fd(*s++, fd);
}

void	ft_putnbr_fd(long nbr, int fd)
{
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	put_nbr_base(nbr, "0123456789", 10, fd);
}

void	ft_puthex_fd(unsigned long nbr, int fd, char form)
{
	char	*low_hex;
	char	*upp_hex;

	low_hex = "0123456789abcdef";
	upp_hex = "0123456789ABCDEF";
	if (form == 'x')
		put_nbr_base((unsigned int)nbr, low_hex, 16, fd);
	else if (form == 'X')
		put_nbr_base((unsigned int)nbr, upp_hex, 16, fd);
	else
		put_nbr_base((unsigned long)nbr, low_hex, 16, fd);
}

static void	put_nbr_base(unsigned long nbr,
	char *base,
	int baseLen,
	int fd
	)
{
	if (nbr >= (unsigned long)baseLen)
		put_nbr_base(nbr / baseLen, base, baseLen, fd);
	ft_putchar_fd(base[nbr % baseLen], fd);
}
