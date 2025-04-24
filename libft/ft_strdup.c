/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:37:07 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/25 19:19:12 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (str == 0)
		return (0);
	while (i < ft_strlen(s))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	a[] = "quesadilla";
	char	*b = ft_strdup(a);
	char	*c = strdup(a);

	printf("Resultado original: %s\n", a);
	printf("Mi resultado: %s\n", b);
	printf("Resultado Real: %s\n", c);
	return (0);
}*/
