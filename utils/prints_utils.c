#include "utils.h"

static void	put_nbr_base(unsigned long nbr, char *base, int base_len, int fd);

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

void	ft_putptr_fd(void *nbr, int fd)
{
	ft_putstr_fd("0x", fd);
	ft_puthex_fd((unsigned long)nbr, fd, 'p');
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
