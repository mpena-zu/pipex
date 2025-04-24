/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:51:26 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/31 20:35:15 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	f(unsigned int i, char c)
{
	if (c)
		i++;
	return (c);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*word;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	word = (char *)malloc(ft_strlen(s) + 1);
	if (word == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		word[i] = f(i, s[i]);
		i++;
	}
	word[i] = '\0';
	return (word);
}
/*
int	main(void)
{
	printf("%s\n", ft_strmapi("abcdefg124", f));
	return (0);
}*/
