/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:25:43 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/10 13:29:44 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*total;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	total = ft_substr(s1, start, end - start + 1);
	return (total);
}
/*
int	main(void)
{
	char	a[] = "cabcdawcba";
	char	b[] = "ab";

	printf("Palabra original: %s\n", a);
	printf("Palabra modificada: %s\n", ft_strtrim(a, b));
	return (0);
}*/
