/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:45:42 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/11 00:03:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

#include "ft_utils.h"
#include "ft_fd.h"
#include "ft_error.h"

/*
	WIFEXITED returns true if child exited with exit function. Then we get 
		status with WEXITSTATUS
	WIFSIGNALED returns true if child exited  receiving a signal. Then we 
		get status (signal used) with WTERMSIG
	WIFSTOPPED returns true if child was stopped. Then we get the stop 
		signal with the macro WSTOPSIG.
*/
static int	ft_parent_get_child_status(int status)
{
	if (WIFEXITED(status) != 0)
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status) != 0)
		return (WTERMSIG(status));
	if (WIFSTOPPED(status) != 0)
		return (WSTOPSIG(status));
	return (EXIT_FAILURE);
}

/*
	WUNTRACED gets status of stopped  or terminated
	WNOHANGS get status indmetiately without waitting to the proccess to terminate
*/
int	ft_parent_execute(int pipefd[2], pid_t pid)
{
	int	status;

	status = 0;
	close(pipefd[PIPE_WRITE_FD]);
	if (dup2(pipefd[PIPE_READ_FD], STDIN_FILENO) == -1)
	{
		ft_error_print_errno(NULL);
		close(pipefd[PIPE_READ_FD]);
		return (EXIT_FAILURE);
	}
	if (waitpid(pid, &status, WNOHANG) == -1)
	{
		ft_error_print_errno(NULL);
		close(pipefd[PIPE_READ_FD]);
		return (EXIT_FAILURE);
	}
	status = ft_parent_get_child_status(status);
	close(pipefd[PIPE_READ_FD]);
	return (status);
}
