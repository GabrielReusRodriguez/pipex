/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:22:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/08 22:32:37 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "libft.h"

void	ft_error_print_errno(void)
{
	perror("Error: ");
}

void	ft_error_print_str(const char *str)
{
	ft_putendl_fd((char *)str, STDERR_FILENO);
}

void	ft_error_print_code(int code)
{
	char	*str;

	str = strerror(code);
	ft_putendl_fd(str, STDERR_FILENO);
}

void	ft_error_print_str_and_exit(const char *str)
{
	ft_error_print_str(str);
	exit(EXIT_FAILURE);
}

void	ft_error_print_errno_and_exit(void)
{
	ft_error_print_errno();
	exit(EXIT_FAILURE);
}
