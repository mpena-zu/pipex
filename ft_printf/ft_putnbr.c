/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:34:50 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/17 22:05:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_int(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == -2147483648)
		return (11);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	char	a;
	int		len;

	len = ft_len_int(nb);
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2147483648", 10);
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		if (nb < 0)
		{
			write(1, "-", 1);
			nb = (-nb);
			if (nb >= 10)
				ft_putnbr(nb / 10);
		}
		a = (nb % 10) + '0';
		write(1, &a, 1);
	}
	return (len);
}
