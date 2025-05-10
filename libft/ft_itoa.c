/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:32:23 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/31 20:02:22 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_int(int n)
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

char	*ft_itoa(int n)
{
	char	*word;
	size_t	len;
	long	num;

	len = ft_len_int(n);
	num = n;
	word = malloc(len + 1);
	if (word == 0)
		return (0);
	word[len] = '\0';
	if (num == 0)
		word[0] = '0';
	if (num < 0)
	{
		word[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		len--;
		word[len] = num % 10 + '0';
		num = num / 10;
	}
	return (word);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
*/
