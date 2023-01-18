#include "utils.h"

void		ft_putchar_fd(char c, int fd);
static void	parse_formats(va_list ap, char form, int fd);

void	ft_fprintf(int fd, char *s, ...)
{
	va_list	ap;

	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			parse_formats(ap, *s, fd);
		}
		else if (*s == '%' && !*(s + 1))
			break ;
		else
			ft_putchar_fd(*s, fd);
		s++;
	}
	va_end(ap);
}

static void	parse_formats(va_list ap, char form, int fd)
{
	if (form == 'c')
		ft_putchar_fd(va_arg(ap, int), fd);
	else if (form == 's')
		ft_putstr_fd(va_arg(ap, char *), fd);
	else if (form == 'i' || form == 'd')
		ft_putnbr_fd(va_arg(ap, int), fd);
	else if (form == 'x' || form == 'X')
		ft_puthex_fd(va_arg(ap, unsigned int), fd, form);
	else if (form == 'u')
		ft_putnbr_fd((unsigned int)va_arg(ap, int), fd);
	else if (form == 'p')
		ft_putptr_fd(va_arg(ap, void *), fd);
	else
		ft_putchar_fd('%', fd);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
