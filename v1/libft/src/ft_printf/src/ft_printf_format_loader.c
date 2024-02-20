/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_loader.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:53:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/09 12:36:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

/*
	width: will be padded with spaces or 0 until reach width.
*/
static t_format	*ft_new_format(void)
{
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (format == NULL)
		return (NULL);
	format->b_hash = 0;
	format->c_data_type = ' ';
	format->b_minus = 0;
	format->b_precision = 0;
	format->n_precision = 0;
	format->b_plus = 0;
	format->b_space = 0;
	format->n_width = 0;
	format->b_zero = 0;
	format->len = 0;
	return (format);
}

/*
if we get 0 we can differ which case is  if we have with 0 
is the first  0 we get, is a flag not a format. 
*/
static void	ft_update_format(char c, t_format *format)
{
	if (c == '+')
		format->b_plus = 1;
	if (c == '#')
		format->b_hash = 1;
	if (ft_isdigit(c) == 1)
	{
		if (c == '0' && format->n_width == 0 && format->b_precision == 0)
		{
			format->b_zero = 1;
		}
		else
		{
			if (format->b_precision == 0)
				format->n_width = format->n_width * 10 + ft_atoi(&c);
			else
				format->n_precision = format->n_precision * 10 + ft_atoi(&c);
		}
	}
	if (c == '-')
		format->b_minus = 1;
	if (c == ' ')
		format->b_space = 1;
	if (c == '.')
		format->b_precision = 1;
	return ;
}

static int	ft_is_format_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p'\
		|| c == 'd' || c == 'i' || c == 'u'\
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

t_format	*ft_load_format(const char *str)
{
	size_t		i;
	t_format	*format;

	format = ft_new_format();
	if (format == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && ft_is_format_char(str[i]) == 0)
	{
		ft_update_format(str[i], format);
		i++;
	}
	if (str[i] != '\0')
		format->c_data_type = str[i];
	format->len = i;
	return (format);
}
