/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:36 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:58:11 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h" 

char	*ft_printf_percent(t_format *format)
{
	char	*c;
	char	character;

	character = '%';
	c = ft_ptr_new_char_buffer(2);
	if (c == NULL)
		return (NULL);
	c[0] = character;
	c[1] = '\0';
	if (c != NULL && format->n_width > 0)
	{
		c = ft_apply_width(c, format);
	}
	return (c);
}
