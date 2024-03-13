/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:39 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:58:35 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

static char	*ft_add_ptr_header(char *str_ptr)
{
	char				*aux;

	aux = ft_strjoin("0x", str_ptr);
	free (str_ptr);
	return (aux);
}

/*
static char	*ft_add_ptr_header(char *str_ptr)
{
	char				*str_head;
	char				*aux;

	str_head = ft_ptr_new_char_buffer(2);
	if (str_head == NULL)
		return (NULL);
	ft_strlcpy(str_head, "0x", 3);
	aux = ft_strjoin(str_head, str_ptr);
	free (str_head);
	free (str_ptr);
	return (aux);
}
*/

static char	*ft_apply_format_and_header(char *str_ptr, t_format *format)
{
	if (format->b_zero == 1)
	{
		if (str_ptr != NULL)
			str_ptr = ft_apply_width(str_ptr, format);
		if (str_ptr != NULL)
			str_ptr = ft_add_ptr_header(str_ptr);
	}
	else
	{
		if (str_ptr != NULL)
			str_ptr = ft_add_ptr_header(str_ptr);
		if (str_ptr != NULL)
			str_ptr = ft_apply_width(str_ptr, format);
	}
	return (str_ptr);
}

char	*ft_printf_ptr(va_list argp, t_format	*format)
{
	void	*ptr;
	char	*str_ptr;	
	size_t	size;

	format->b_minus = 0;
	ptr = va_arg(argp, void *);
	if (ptr == NULL)
	{
		size = 1 + 1;
		str_ptr = ft_ptr_new_char_buffer(size);
		if (str_ptr == NULL)
			return (NULL);
		ft_strlcpy(str_ptr, "0", size);
	}
	else
		str_ptr = ft_dtoh((unsigned long)ptr, 0);
	if (str_ptr == NULL)
		return (NULL);
	if (format->n_width > 0)
		str_ptr = ft_apply_format_and_header(str_ptr, format);
	else
		str_ptr = ft_add_ptr_header(str_ptr);
	return (str_ptr);
}
