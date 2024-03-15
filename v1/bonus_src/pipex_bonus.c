/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:05:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/15 14:19:00 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "ft_environment_bonus.h"
#include "ft_error_bonus.h"
#include "ft_exec_bonus.h"
#include "ft_fd_bonus.h"
#include "ft_files_bonus.h"
#include "ft_ptr_bonus.h"
#include "ft_utils_bonus.h"
#include "ft_parent_bonus.h"

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

static int	ft_main_execute_pipe(char **argv, t_env env, \
				int initial_cmd, int final_cmd)
{
	int	status;
	int	i;

	status = -1;
	i = initial_cmd;
	while (i < final_cmd)
	{
		status = ft_exec_redir_and_cmd(argv[i], env, NO_FD);
		if (status == -1)
			return (status);
		i++;
	}
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	int		fdin;
	int		fdout;
	t_env	env;
	int		status;

	if (argc > 5)
	{
		fdin = ft_file_open(argv[1], INFILE, NULL);
		fdout = ft_file_open(argv[argc - 1], OUTFILE, argv[1]);
		ft_main_check_fds(fdin, fdout);
		ft_main_dups(fdin, fdout);
		env = ft_env_new(envp);
		status = ft_main_execute_pipe(argv, env, 3, argc - 2);
		if (status != 0)
		{
			ft_main_free_resources(fdin, fdout, env, argv[argc - 1]);
			exit(EXIT_FAILURE);
		}
		status = ft_exec_redir_and_cmd(argv[argc - 2], env, fdout);
		status = ft_parent_get_last_child_status(argc - 4);
		ft_main_free_resources(fdin, fdout, env, NULL);
		exit (status);
	}
	else
		ft_error_print_str_and_exit("Invalid number of arguments.", \
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
