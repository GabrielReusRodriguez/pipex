/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:05:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/15 00:25:39 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_environment.h"
#include "ft_error.h"
#include "ft_exec.h"
#include "ft_fd.h"
#include "ft_files.h"
#include "ft_ptr.h"
#include "ft_utils.h"
#include "ft_parent.h"

static	void	ft_main_check_fds(int fdin, int fdout)
{
	if (fdin < 0 || fdout < 0)
	{
		ft_file_close(fdin, fdout);
		ft_error_print_errno_and_exit(NULL, EXIT_FAILURE);
	}
}

static void	ft_main_dups(int fdin, int fdout)
{
	if (dup2(fdin, STDIN_FILENO) == -1 || dup2(fdout, STDOUT_FILENO) == -1)
	{
		ft_file_close(fdin, fdout);
		ft_error_print_errno_and_exit(NULL, EXIT_FAILURE);
	}
}

static void	ft_main_free_resources(int fdin, int fdout, t_env env, \
				const char *file_output)
{
	ft_file_close(fdin, fdout);
	ft_ptr_free_matrix(env.path);
	if (file_output != NULL)
		unlink(file_output);
}

static void	ft_main_exec_pipe(char **argv, t_env env, int fdin, int fdout)
{
	int	status;

	status = ft_exec_redir_and_cmd(argv[2], env, NO_FD);
	if (status != 0)
	{
		ft_main_free_resources(fdin, fdout, env, argv[4]);
		exit(status);
	}
	status = ft_exec_redir_and_cmd(argv[3], env, fdout);
	if (status != 0)
	{
		ft_main_free_resources(fdin, fdout, env, argv[4]);
		exit(status);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;
	t_env	env;
	int		status;

	if (argc == 5)
	{
		fdin = ft_file_open(argv[1], INFILE);
		fdout = ft_file_open(argv[4], OUTFILE);
		ft_main_check_fds(fdin, fdout);
		ft_main_dups(fdin, fdout);
		env = ft_env_new(envp);
		ft_main_exec_pipe(argv, env, fdin, fdout);
		ft_main_free_resources(fdin, fdout, env, NULL);
		status = ft_parent_get_last_child_status(argc - 3);
		exit (status);
	}
	else
	{
		ft_error_print_str("Invalid number of arguments.");
		return (EXIT_FAILURE);
	}
	return (0);
}
