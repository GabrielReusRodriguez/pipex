/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:05:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/10 03:12:00 by gabriel          ###   ########.fr       */
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


static	void	ft_main_check_fds(int fdin, int fdout)
{
	if (fdin < 0 || fdout < 0)
	{
		ft_file_close(fdin, fdout);
		ft_error_print_errno();
		exit(EXIT_SUCCESS);
	}
}

static void	ft_main_dups(int fdin, int fdout)
{
	if (dup2(fdin, STDIN_FILENO) == -1 || dup2(fdout, STDOUT_FILENO) == -1)
	{
		ft_file_close(fdin, fdout);
		ft_error_print_errno_and_exit();
	}
}

static void	ft_main_free_resources(int fdin, int fdout, t_env env)
{
	ft_file_close(fdin, fdout);
	ft_ptr_free_matrix(env.path);
}

int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;
	t_env	env;
	int     status;

	if (argc == 5)
	{
		fdin = ft_file_open(argv[1], INFILE);
		fdout = ft_file_open(argv[4], OUTFILE);
		ft_main_check_fds(fdin, fdout);
		ft_main_dups(fdin, fdout);
		env = ft_env_new(envp);
		status = ft_exec_redir_and_cmd(argv[2], env, NO_FD);
		if (status != 0)
		{
			ft_main_free_resources(fdin, fdout, env);
			return (status);
		}
		status = ft_exec_redir_and_cmd(argv[3], env, fdout);
		ft_main_free_resources(fdin, fdout, env);
		return (status);
	}
	else
		ft_error_print_str("Invalid number of arguments.");
	return (1);
}
