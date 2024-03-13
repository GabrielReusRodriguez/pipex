/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:09:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:58:43 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_printf_str(va_list argp, t_format	*format)
{
	char	*str;
	char	*argp_str;
	size_t	size;

	argp_str = va_arg(argp, char *);
	if (argp_str == NULL)
	{
		size = 6 + 1;
		str = ft_ptr_new_char_buffer(size);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, "(null)", size);
	}
	else
		str = ft_strdup(argp_str);
	if (str != NULL && format->n_width > 0)
		str = ft_apply_width(str, format);
	return (str);
}
