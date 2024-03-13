/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:05:41 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/13 23:36:58 by gabriel          ###   ########.fr       */
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

/*
static	void	ft_main_check_fds(int fdin, int fdout)
{
	if (fdin < 0 || fdout < 0)
	{
		ft_file_close(fdin, fdout);
		ft_error_print_errno_and_exit(NULL, EXIT_SUCCESS);
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

static int	ft_main_exec_pipe(char **argv, t_env env, int fdin, int fdout)
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
	return (status);
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
		status = ft_main_exec_pipe(argv, env, fdin, fdout);
		ft_main_free_resources(fdin, fdout, env, NULL);
		exit (status);
	}
	else
		ft_error_print_str("Invalid number of arguments.");
	return (0);
}
*/

#include "libft.h"
#include "ft_pipelist.h"
#include "ft_cmd.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_list  *pipelist;
	t_list  *node;
	char ** args;
	size_t	i;

	pipelist = ft_pipelist_create(argv, argc, envp);
	if (pipelist == NULL)
	{
		ft_putendl_fd("ERRROR creating pipe queue.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	node = pipelist;
	printf("Cola\n");
	while (node != NULL)
	{
		printf("cmd: %s\n", ((t_cmd *)node->content)->cmd);
		args = ((t_cmd *)node->content)->args;
		printf("args: \n");
		i = 0;
		while (args[i] != NULL)
		{
			printf("\t%s\n", args[i]);
			i++;
		}
		node = node->next;
	}
	printf("FIN Cola\n");
	ft_lstclear(&pipelist, &ft_cmd_free);
	return (EXIT_SUCCESS);
}