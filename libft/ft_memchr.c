/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:26:06 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/20 15:43:00 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	str1;

	i = 0;
	str = (unsigned char *)s;
	str1 = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == str1)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s[25] = "jesucristo";
	int		c = 117;
	size_t	n = 7;
	void	*result;

	result = ft_memchr(s, c, n);
	printf("Ha encontrado algo?: %s\n", (char *)result);
	return (0);
}*/
