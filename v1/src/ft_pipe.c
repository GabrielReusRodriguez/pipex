/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:07:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/20 23:16:59 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h> 
#include "ft_error.h"
#include "ft_pipe.h"


t_pipe	ft_pipe_new(void)
{
	t_pipe	_pipe;
	int	fds[2];
	int error;

	error = pipe(fds);
	if (error == -1)
	{
		ft_error_print_code(errno);
		exit(EXIT_FAILURE);
	}
	_pipe.rd_fd = fds[0];
	_pipe.wr_fd = fds[1];
	return (_pipe);
}
