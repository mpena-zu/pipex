/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:18:09 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/20 18:07:33 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t				i;
	size_t				j;
	size_t				save;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			save = i;
			j = 0;
			while (big[i + j] == little[j] && little[j] != '\0'
				&& (i + j) < len)
				j++;
			if (little[j] == '\0')
				return ((char *)(big + save));
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str[] = "pequeño el mundo";
	char	enc[] = "el";

	printf("Encontro algo?: %s\n", ft_strnstr(str, enc, 5));
	return (0);
}*/
