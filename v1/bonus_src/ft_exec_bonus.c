/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:02:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:26:15 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "ft_environment_bonus.h"
#include "ft_fd_bonus.h"
#include "ft_files_bonus.h"
#include "ft_error_bonus.h"
#include "ft_parent_bonus.h"
#include "ft_ptr_bonus.h"
#include "ft_child_bonus.h"

/*
	execve replaces current process with the cmd and if everything 
		is ok it WILL NOT return.
		It only returns if an error occurs.
*/
void	ft_exec_cmd(char *cmd, t_env env)
{
	char	**cmd_args;
	char	*cmd_path;

	cmd_args = ft_split(cmd, ' ');
	if (cmd_args == NULL)
		ft_error_print_str_and_exit("Error treating cmd args", EXIT_FAILURE);
	cmd_path = ft_utils_which(cmd_args, env.path);
	if (cmd_path == NULL)
	{
		ft_ptr_free_matrix(cmd_args);
		ft_error_print_str_and_exit("Error command not found", EXIT_FAILURE);
	}
	if (execve(cmd_path, cmd_args, env.env) < 0)
	{
		free(cmd_path);
		ft_ptr_free_matrix(cmd_args);
		ft_error_print_str_and_exit("Error executing cmd", EXIT_FAILURE);
	}
}

int	ft_exec_redir_and_cmd(char *cmd, t_env env, int fdout)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		ft_error_print_errno(NULL);
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid != 0)
	{
		if (pid == -1)
		{
			ft_error_print_errno(NULL);
			ft_file_close(pipefd[PIPE_READ_FD], pipefd[PIPE_WRITE_FD]);
			return (EXIT_FAILURE);
		}
		return (ft_parent_execute(pipefd));
	}
	else
		ft_child_execute(pipefd, cmd, env, fdout);
	return (EXIT_SUCCESS);
}
