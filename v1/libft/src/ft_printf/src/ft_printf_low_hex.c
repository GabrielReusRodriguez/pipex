/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_low_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:19:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/01/31 21:04:22 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*ft_printf_low_hex(va_list argp, t_format	*format)
{
	unsigned int	arg;
	char			*hex_num;

	arg = va_arg(argp, unsigned int);
	hex_num = ft_printf_htoa(arg, 0, format);
	return (hex_num);
}
