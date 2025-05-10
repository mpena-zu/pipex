/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:15:35 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/10 13:29:37 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*total;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	total = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (total == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		total[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		total[i + j] = s2[j];
		j++;
	}
	total[i + j] = '\0';
	return (total);
}
/*
int	main(void)
{
	char	a[] = "patada ";
	char	b[] = "voladora";

	printf("El resultado de la cadena concatenada es: %s\n", ft_strjoin(a, b));
	return (0);
}*/
