/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:50:48 by mpena-zu          #+#    #+#             */
/*   Updated: 2025/02/18 11:50:01 by mpena-zu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printf_p(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hexa(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_hexa_upper(va_arg(args, unsigned int)));
	else if (c == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	va_list	args;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		if (format[i] == '%')
		{
			i++;
			len = len + conversion(format[i], args);
		}
		else
			len = len + write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	int	res_printf;
	int	res_ft_printf;

	res_printf = printf(NULL);
	res_ft_printf = ft_printf(NULL);
	printf("printf = %i\n", res_printf);
	printf("ft_printf = %i\n", res_ft_printf);
	return (0);
} */
