/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 17:03:26 by amoura-d          #+#    #+#             */
/*   Updated: 2026/06/22 13:12:47 by amoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_pointer(va_list ap);
static int	print_format(char specifier, va_list ap);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			if (*format == '\0')
				break ;
			count += print_format(*format, ap);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

static int	handle_pointer(va_list ap)
{
	unsigned long long	ptr;
	int					count;

	count = 0;
	ptr = (unsigned long long)va_arg(ap, void *);
	if (!ptr)
		return (ft_str("(nil)"));
	count += write(1, "0x", 2);
	count += ft_putnbr_base(ptr, HEX_LOW);
	return (count);
}

static int	print_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_str(va_arg(ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), DEC));
	else if (specifier == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), HEX_LOW));
	else if (specifier == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), HEX_UP));
	else if (specifier == 'p')
		return (handle_pointer(ap));
	else if (specifier == '%')
		return (ft_char('%'));
	return (ft_char(specifier));
}
