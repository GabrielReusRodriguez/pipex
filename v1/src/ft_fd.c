/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:53:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/10 18:55:16 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_error.h"
#include "ft_fd.h"
#include "ft_utils.h"

t_bool	ft_fd_pipe_close(int fd[2], int which_fd)
{
	if (which_fd == PIPE_READ_FD && close(fd[PIPE_READ_FD]) == -1)
	{
		ft_error_print_errno(NULL);
		return (FALSE);
	}
	if (which_fd == PIPE_WRITE_FD && close(fd[PIPE_WRITE_FD]) == -1)
	{
		ft_error_print_errno(NULL);
		return (FALSE);
	}
	if (which_fd == PIPE_ALL_FD)
	{
		if (close(fd[PIPE_READ_FD]) == -1 || close(fd[PIPE_WRITE_FD]) == -1)
		{
			ft_error_print_errno(NULL);
			return (FALSE);
		}
	}
	return (TRUE);
}
