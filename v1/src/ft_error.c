/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:22:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 21:47:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_error.h"
#include "libft.h"


void	ft_error_print_errno(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}

void	ft_error_print_str(const char *str)
{
	ft_putendl_fd((char *)str,STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_error_print_code(int code)
{
	char	*str;

	str = strerror(code);
	ft_putendl_fd(str,STDERR_FILENO);
	exit(EXIT_FAILURE);
}
