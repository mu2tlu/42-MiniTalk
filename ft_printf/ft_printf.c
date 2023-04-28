/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumutlu <mumutlu@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:07:55 by mumutlu           #+#    #+#             */
/*   Updated: 2023/04/28 17:07:56 by mumutlu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_scan(char c, va_list macro)
{
	if (c == 'c')
		return (ft_putchar(va_arg(macro, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(macro, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putpointer(va_arg(macro, void *)) + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(macro, int)));
	else if (c == 'u')
		return (ft_putunint(va_arg(macro, unsigned int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'x')
		return (ft_convert(va_arg(macro, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_convert(va_arg(macro, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_convert(size_t num, char *set)
{
	char			*buffer;
	char			*ptr;
	int				base;
	int				counter;

	buffer = malloc(sizeof(char) * 50);
	base = ft_strlen(set);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = set[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = set[num % base];
		num /= base;
	}
	counter = ft_putstr(ptr);
	free(buffer);
	return (counter);
}

int	ft_printf(const char *sign, ...)
{
	va_list	macro;
	int		i;
	int		len;

	va_start(macro, sign);
	i = 0;
	len = 0;
	while (sign[i])
	{
		if (sign[i] == '%')
		{
			len += ft_scan(sign[i + 1], macro);
			i++;
		}
		else
			len += write(1, &sign[i], 1);
		i++;
	}
	va_end(macro);
	return (len);
}
