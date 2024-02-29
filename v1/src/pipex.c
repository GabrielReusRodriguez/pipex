/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:56:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 23:25:29 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_environment.h"
#include "ft_error.h"
#include "ft_get_next_line.h"
#include "libft.h"
#include "ft_pipe.h"
#include "ft_process.h"
#include "ft_utils.h"

static void	ft_pipex_read_input(const char * file_name, t_pipe out_pipe)
{
	int		status;
	int 	fd;
	char	*line;

	close (out_pipe.rd_fd);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error_print_errno();
	line = "";
	dup2(out_pipe.wr_fd, STDIN_FILENO);
	while ( line != NULL)
	{
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL)
		{
			ft_putstr_fd(line, out_pipe.wr_fd);
			free(line);
		}
	}
	close(fd);
	close(out_pipe.wr_fd);
//	waitpid(pid_soon, &status, 0);
}

static void	ft_pipex_write_output(const char * file_name,t_pipe in_pipe)
{
	int 	fd;
	char	*line;

	close (in_pipe.wr_fd);
	fd = open(file_name, O_WRONLY | O_CREAT, 744);
	if (fd < 0)
		ft_error_print_errno();
	line = "";
	//dup2(in_pipe.rd_fd, fd);
	while ( line != NULL)
	{
		line = ft_get_next_line_many_fds(in_pipe.rd_fd);
		if (line != NULL)
		{
			ft_putstr_fd(line, fd);
			free(line);
		}
	}
	close(fd);
	close(in_pipe.rd_fd);
}

static	void ft_execute_commands(t_main_params params, const char **path, \
		t_pipe *pipes)
{
	size_t 		i;
	t_process	*process;
	
	i = 2;
	while (i < (size_t)params.argc)
	{
		process = ft_process_new(params.argv[i], path, pipes, i);
		ft_process_execute(process, i, params);
		ft_process_destroy(process);
		i++;
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_main_params	params;
	char			**path_folders;
	t_pipe			*v_pipes;
	t_process		*process;
	size_t			num_pipes;

	params = ft_utils_create_params(argc, argv, envp);
	if (params.argc <= 5)
		ft_error_print_str("Error\nBad number of arguments\n");
	num_pipes = params.argc - 3;
	path_folders = ft_env_get_path(params.envp);
	v_pipes = ft_pipelist_create(num_pipes);
	if (v_pipes == NULL)
		ft_error_print_str("Error\nError in malloc\n");
	ft_execute_commands(params, (const char **)path_folders, v_pipes);
	ft_pipelist_destroy(v_pipes, num_pipes);
	return (0);
}
