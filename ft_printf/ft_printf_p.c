/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:23:31 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/18 11:45:23 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_hexa_conversion_p(unsigned int n)
{
	if (n <= 9)
		return (n + '0');
	if (n == 10)
		return ('a');
	if (n == 11)
		return ('b');
	if (n == 12)
		return ('c');
	if (n == 13)
		return ('d');
	if (n == 14)
		return ('e');
	if (n == 15)
		return ('f');
	return (0);
}

static int	ft_hexa_p(unsigned long n)
{
	char	word;
	int		len;

	len = 0;
	if (n >= 16)
		len = len + ft_hexa_p(n / 16);
	word = ft_hexa_conversion_p(n % 16);
	write(1, &word, 1);
	len++;
	return (len);
}

int	ft_printf_p(void *n)
{
	int				len;
	unsigned long	ptr;

	len = 0;
	ptr = (uintptr_t)n;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		len = 5;
	}
	else
	{
		write(1, "0x", 2);
		len = 2 + ft_hexa_p(ptr);
	}
	return (len);
}
