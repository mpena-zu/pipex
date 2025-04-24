/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:58:20 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/31 18:00:02 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*reverse;

	i = 0;
	reverse = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (char)c)
			reverse = (char *)&s[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (reverse);
}
/*
int	main(void)
{
	char	a[] = "felicidades";

	printf("El resultado e: %s\n", ft_strrchr(a, 'i'));
	return (0);
}*/
