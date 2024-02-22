/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:22:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/22 23:40:51 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "ft_error.h"
#include "libft.h"


void	ft_error_print_errno(void)
{
	perror("Error: ");
}

void	ft_error_print_str(const char *str)
{
	perror(str);
}

void	ft_error_print_code(int code)
{
	char	*str;

	str = strerror(code);
	ft_putstr_fd(str,STDERR_FILENO);
}
