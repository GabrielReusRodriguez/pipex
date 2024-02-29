/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:07:00 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 21:34:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_error.h"
#include "ft_pipe.h"


static	t_pipe	ft_pipe_create(void)
{
	t_pipe	pipe;

	pipe.rd_fd = -1;
	pipe.wr_fd = -1;
	return (pipe);
}

t_pipe	ft_pipe_new(void)
{
	t_pipe	_pipe;
	int	fds[2];
	int error;

	_pipe = ft_pipe_create();
	error = pipe(fds);
	if (error == -1)
	{
		ft_error_print_errno();
		exit(EXIT_FAILURE);
		//return (_pipe);
	}
	_pipe.rd_fd = fds[0];
	_pipe.wr_fd = fds[1];
	return (_pipe);
}

t_bool	ft_pipe_check(t_pipe pipe)
{
	if (pipe.rd_fd == -1 || pipe.wr_fd == -1)
		return FALSE;
	return TRUE;
}