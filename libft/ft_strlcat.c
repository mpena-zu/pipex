/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 20:53:33 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/28 20:37:52 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	if (size <= i)
		return (i + ft_strlen(src));
	while (src[j] != '\0' && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int main(void)
{
    char dst[0] = '\0';
    const char *src = "blanco";
    size_t size = 15;
    size_t result = ft_strlcat(dst, src, size);

    printf("Cadena resultante: %s\n", dst);
    printf("Tamaño total de la cadena concatenada: %zu\n", result);
    return (0);
}*/
