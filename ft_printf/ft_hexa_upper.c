/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_upper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:11:45 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/18 11:13:21 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_hexa_conversion_upper(unsigned int n)
{
	if (n <= 9)
		return (n + '0');
	if (n == 10)
		return ('A');
	if (n == 11)
		return ('B');
	if (n == 12)
		return ('C');
	if (n == 13)
		return ('D');
	if (n == 14)
		return ('E');
	if (n == 15)
		return ('F');
	return (0);
}

int	ft_hexa_upper(unsigned int n)
{
	char	word;
	int		len;

	len = 0;
	if (n >= 16)
		len = len + ft_hexa_upper(n / 16);
	word = ft_hexa_conversion_upper(n % 16);
	write(1, &word, 1);
	len++;
	return (len);
}
