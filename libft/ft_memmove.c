/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:56:53 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/30 21:03:07 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	const unsigned char	*src1;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (src1 < dest1)
	{
		while (n--)
			dest1[n] = src1[n];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	a[50] = "Hello, World!";
	char	b[50] = "Hello, World!";

	memmove(a + 2, a, 20);
	printf("%s\n", a + 2);
	ft_memmove(b + 2, b, 20);
	printf("%s\n", b + 2);
	return (0);
}*/
