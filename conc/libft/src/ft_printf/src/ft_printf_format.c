/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:37:33 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:57:49 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_apply_hash_format(char *str, unsigned long n, t_format *format)
{
	char	*aux;

	if (format->b_hash == 1)
	{
		if (format->c_data_type == 'x' && n != 0)
		{
			aux = str;
			str = ft_strjoin("0x", str);
			free (aux);
		}
		if (format->c_data_type == 'X' && n != 0)
		{
			aux = str;
			str = ft_strjoin("0X", str);
			free (aux);
		}
	}
	return (str);
}

char	*ft_apply_sign_format(char *str, int positive, t_format *format)
{
	char	*aux;

	if (format->b_plus == 1)
	{
		if (positive == 1)
		{
			aux = str;
			str = ft_strjoin("+", str);
			free (aux);
		}
	}
	if (format->b_space == 1)
	{
		if (positive == 1)
		{
			aux = str;
			str = ft_strjoin(" ", str);
			free (aux);
		}
	}
	return (str);
}

/*
Be carefull! a - overwrites the 0 flag (man says it)
If it is a pointer and we fill it with 0s, we substract 2 because 
all pointers start with 0x.
If we have to write spaces then we should write them afer /before
0xhex
*/
static char	*ft_create_padding(size_t size, t_format *format)
{
	char	*aux;
	char	*padding;
	char	chr_padding;

	if (format->b_zero == 1 && format->b_minus == 0)
	{
		chr_padding = '0';
	}
	else
		chr_padding = ' ';
	if (format->c_data_type == 'p' && format->b_zero == 1)
		size = size - 2;
	padding = ft_calloc(size + 1, 1);
	if (padding == NULL)
		return (NULL);
	aux = padding;
	padding = ft_memset(padding, chr_padding, size);
	if (padding == NULL)
	{
		free(aux);
		return (NULL);
	}
	return (padding);
}

char	*ft_apply_width(char *str, t_format *format)
{
	size_t	width;
	char	*aux;
	char	*padding;

	if (format->n_width > 0)
	{
		width = ft_strlen(str);
		if (width < format->n_width)
		{
			padding = ft_create_padding(format->n_width - width, format);
			if (padding == NULL)
				return (ft_ptr_free(str));
			aux = str;
			if (format->b_minus == 1)
				str = ft_strjoin(str, padding);
			else
				str = ft_strjoin(padding, str);
			free(padding);
			if (str == NULL)
				return (ft_ptr_free(aux));
			free(aux);
		}
	}
	return (str);
}
