/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:39:31 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/10 14:11:33 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(char const *str, char c)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			i++;
			while (str[i] && str[i + 1] && str[i] != c)
				i++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

int	len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

void	free_mem(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		j;

	j = 0;
	word = malloc((count(s, c) + 1) * sizeof(char *));
	if (!s || !word)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			word[j] = ft_substr(s, 0, len(s, c));
			if (word[j] == NULL)
			{
				free_mem(word, j);
				return (NULL);
			}
			s = s + len(s, c);
			j++;
		}
	}
	word[j] = NULL;
	return (word);
}
/*
int main(void)
{
    char **result = ft_split(NULL, ' ');
	int			i = 0;

   	if (result != NULL)
    {
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            i++;
        }
    }
	printf("\n");
    return 0;
}*/
