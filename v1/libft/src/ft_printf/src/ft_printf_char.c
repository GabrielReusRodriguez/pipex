/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:04:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:57:33 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

/*
We return pointers to char so if char is \0 when we print only one.
*/
char	*ft_printf_char(va_list argp, t_format *format)
{
	char	*c;
	char	character;
	size_t	size;

	(void)format;
	character = va_arg(argp, int);
	if (character != '\0')
		size = 2;
	else
		size = 1;
	c = (char *)malloc(size);
	if (c == NULL)
		return (NULL);
	c[size - 1] = '\0';
	if (size > 1)
		c[0] = character;
	if (c != NULL && format->n_width > 0)
		c = ft_apply_width(c, format);
	return (c);
}
