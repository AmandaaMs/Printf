/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoura-d <amoura-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 08:32:44 by amoura-d          #+#    #+#             */
/*   Updated: 2026/06/22 13:15:30 by amoura-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_str(char	*str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str != '\0')
	{
		count += ft_char((int) *str);
		++str;
	}
	return (count);
}

int	ft_putnbr(int nbr)
{
	long	n;
	int		count;

	count = 0;
	n = nbr;
	if (n < 0)
	{
		count += write(1, "-", 1);
			n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_char((n % 10) + '0');
	return (count);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				count;
	unsigned long	base_len;

	count = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += ft_char(base[nbr % base_len]);
	return (count);
}


