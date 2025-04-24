/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-zu <mpena-zu@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:52:18 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/01/19 19:29:24 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	s[3] = {1, 2, 3};

	printf("Antes de bzero: %d\n", s[0]);
	printf("Antes de bzero: %d\n", s[1]);
	printf("Antes de bzero: %d\n", s[2]);
	ft_bzero(s, 5);
	printf("Despues de bzero: %d\n", s[0]);
	printf("Despues de bzero: %d\n", s[1]);
	printf("Despues de bzero: %d\n", s[2]);
	return (0);
}*/
