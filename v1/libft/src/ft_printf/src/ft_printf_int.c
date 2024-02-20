/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:14:49 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:58:02 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char	*ft_printf_int(va_list argp, t_format	*format)
{
	int		arg_value;
	char	*num;

	arg_value = va_arg(argp, int);
	num = ft_itoa(arg_value);
	if (num != NULL)
		num = ft_apply_sign_format(num, arg_value >= 0, format);
	if (num != NULL)
		num = ft_apply_width(num, format);
	return (num);
}
