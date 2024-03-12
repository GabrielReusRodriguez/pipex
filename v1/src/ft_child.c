/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:45:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 21:36:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_environment.h"
#include "ft_error.h"
#include "ft_exec.h"
#include "ft_fd.h"

/*
	We do NOT close write pipe because EXIT does it when execve ends the 
		child  process.
*/
void	ft_child_execute(int pipefd[2], char *cmd, t_env env, int fdout)
{
	close(pipefd[PIPE_READ_FD]);
	if (fdout == NO_FD)
	{
		if (dup2(pipefd[PIPE_WRITE_FD], STDOUT_FILENO) == -1)
		{
			close(pipefd[PIPE_WRITE_FD]);
			ft_error_print_errno_and_exit(NULL, EXIT_FAILURE);
		}
	}
	else
	{
		if (dup2(fdout, STDOUT_FILENO) == -1)
		{
			close(pipefd[PIPE_WRITE_FD]);
			ft_error_print_errno_and_exit(NULL, EXIT_FAILURE);
		}
	}
	ft_exec_cmd(cmd, env);
}
