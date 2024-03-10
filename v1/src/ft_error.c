/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:22:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/10 18:50:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "libft.h"

void	ft_error_print_errno(const char *msg)
{
	if (msg == NULL)
		perror("Error");
	else
		perror(msg);
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

void	ft_error_print_str_and_exit(const char *str, int exit_status)
{
	ft_error_print_str(str);
	exit(exit_status);
}

void	ft_error_print_errno_and_exit(const char * msg, int exit_status)
{
	ft_error_print_errno(msg);
	exit(exit_status);
}
