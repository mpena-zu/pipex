/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 19:20:31 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/10 13:37:31 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*total;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		total = (char *)malloc(1);
		if (!total)
			return (NULL);
		total[0] = '\0';
		return (total);
	}
	total = (char *)malloc(len + 1);
	if (!total)
		return (NULL);
	while (i < len)
	{
		total[i] = s[i + start];
		i++;
	}
	return (total[i] = '\0', total);
}
/*
int	main(void)
{
	char	a[] = "felicidades";

	printf("El texto original es: %s\n", a);
	printf("El texto resultante es: %s\n", ft_substr(a, 4, 4));
	return (0);
}*/
