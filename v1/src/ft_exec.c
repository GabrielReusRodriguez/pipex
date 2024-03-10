/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:02:17 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/10 18:57:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "ft_environment.h"
#include "ft_fd.h"
#include "ft_files.h"
#include "ft_error.h"
#include "ft_parent.h"
#include "ft_ptr.h"
#include "ft_child.h"

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
		//ft_error_print_str_and_exit("Error treating cmd path");
        exit(EXIT_FAILURE);
	}
	if (execve(cmd_path, cmd_args, env.env) < 0)
	{
		free(cmd_path);
		ft_ptr_free_matrix(cmd_args);
		ft_error_print_str_and_exit("Error executing cmd", EXIT_FAILURE);
	}
	free (cmd_path);
	ft_ptr_free_matrix(cmd_args);
	exit(EXIT_SUCCESS);
}

int ft_exec_redir_and_cmd(char *cmd, t_env env, int fdout)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		ft_error_print_errno(NULL);
		return (FALSE);
	}
	pid = fork();
	if (pid != 0)
	{
		if (pid == -1)
		{
			ft_error_print_errno(NULL);
			ft_file_close(pipefd[PIPE_READ_FD], pipefd[PIPE_WRITE_FD]);
			return (1);
		}
		return (ft_parent_execute(pipefd, pid));
	}
	else
		ft_child_execute(pipefd, cmd, env, fdout);
	return (0);
}
