/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:30 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:59:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include <stdlib.h>

static char	*ft_formated_data_2_string(va_list argp, t_format *format)
{
	char	*str_formated;

	str_formated = NULL;
	if (format->c_data_type == 'c')
		str_formated = ft_printf_char(argp, format);
	if (format->c_data_type == '%')
		str_formated = ft_printf_percent(format);
	if (format->c_data_type == 's')
		str_formated = ft_printf_str(argp, format);
	if (format->c_data_type == 'd')
		str_formated = ft_printf_dec(argp, format);
	if (format->c_data_type == 'i')
		str_formated = ft_printf_int(argp, format);
	if (format->c_data_type == 'u')
		str_formated = ft_printf_usgn(argp, format);
	if (format->c_data_type == 'p')
		str_formated = ft_printf_ptr(argp, format);
	if (format->c_data_type == 'x')
		str_formated = ft_printf_low_hex(argp, format);
	if (format->c_data_type == 'X')
		str_formated = ft_printf_up_hex(argp, format);
	return (str_formated);
}

/*
This function prints %chars. Be carefull!! the %c accepts \0 char and
libfts ft_putstr function prints string without \0.

The solution is to print a char in these cases.
*/
static int	ft_print_formated_data(va_list argp, t_format *format)
{
	int		num_bytes;
	char	*str_formated;
	size_t	len;

	str_formated = ft_formated_data_2_string(argp, format);
	if (str_formated == NULL)
		return (-1);
	len = ft_strlen(str_formated);
	if (format->c_data_type == 'c' && len == 0)
	{
		num_bytes = ft_iputchar_fd('\0', 1);
		free(str_formated);
		return (num_bytes);
	}
	num_bytes = ft_iputstr_fd(str_formated, 1);
	free (str_formated);
	return (num_bytes);
}

static int	ft_print_special_char(char *str, size_t *i, va_list argp)
{
	t_format	*format;
	int			num_bytes;

	format = ft_load_format(str + *i);
	if (format == NULL)
		return (-1);
	*i = *i + format->len;
	num_bytes = ft_print_formated_data(argp, format);
	free (format);
	return (num_bytes);
}

int	ft_printf(char const *str, ...)
{
	va_list		argp;
	int			num_bytes;
	int			printed_bytes;
	size_t		i;

	num_bytes = 0;
	i = 0;
	va_start(argp, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			printed_bytes = ft_iputchar_fd(str[i], 1);
		else
		{
			i++;
			printed_bytes = ft_print_special_char((char *)str, &i, argp);
		}
		if (printed_bytes < 0)
			return (printed_bytes);
		num_bytes = num_bytes + printed_bytes;
		i++;
	}
	va_end(argp);
	return (num_bytes);
}
