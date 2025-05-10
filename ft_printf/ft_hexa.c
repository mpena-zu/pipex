/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:08:44 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/18 11:11:20 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_hexa_conversion(unsigned int n)
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

int	ft_hexa(unsigned int n)
{
	char	word;
	int		len;

	len = 0;
	if (n >= 16)
		len = len + ft_hexa(n / 16);
	word = ft_hexa_conversion(n % 16);
	write(1, &word, 1);
	len++;
	return (len);
}
