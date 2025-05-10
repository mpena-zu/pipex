/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:52:21 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/23 20:35:53 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;
	size_t	total;

	i = 0;
	total = nmemb * size;
	str = (char *)malloc(total);
	if (str == 0)
		return (0);
	while (i < total)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
/*
int	main(void)
{
	int	a = 2;
	int	b = 3;
	char	*str = ft_calloc(a, b);
	char	*real_str = calloc(a, b);

	printf("%s\n", str);
	printf("Real: %s\n", real_str);
	return (0);
}*/
