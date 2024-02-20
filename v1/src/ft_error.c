/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:22:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/20 00:31:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_error.h"


void	ft_error_print_str(char *str)
{
	perror(str);
}

void	ft_error_print_code(int code)
{
	char	*str;

	str = strerror(code);
	ft_error_print_str(str);
}
