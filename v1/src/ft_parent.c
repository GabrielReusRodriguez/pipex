/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:45:42 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/10 03:25:56 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>

#include "ft_utils.h"
#include "ft_fd.h"
#include "ft_error.h"

int ft_parent_execute(int pipefd[2], pid_t pid)
{
	int status;
	
	status = 0;
	close(pipefd[PIPE_WRITE_FD]);
	if (dup2(pipefd[PIPE_READ_FD], STDIN_FILENO) == -1)
	{
		ft_error_print_errno();
		close(pipefd[PIPE_READ_FD]);
		return (1);
	}
	if (waitpid(pid, &status, 0) == -1)
    {
        ft_error_print_errno();
		close(pipefd[PIPE_READ_FD]);
		return (1);
    }
    return (WEXITSTATUS(status));
	//return (status);
}
/*
t_bool	ft_parent_execute(int pipefd[2], pid_t pid)
{
	int status;
	
	close(pipefd[PIPE_WRITE_FD]);
	if (dup2(pipefd[PIPE_READ_FD], STDIN_FILENO) == -1)
	{
		ft_error_print_errno();
		close(pipefd[PIPE_READ_FD]);
		return (FALSE);
	}
	waitpid(pid, &status, 0);
	return (TRUE);
}
*/