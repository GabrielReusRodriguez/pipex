/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:56:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/03 23:08:03 by gabriel          ###   ########.fr       */
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
#include <sys/types.h>

/*
static int	ft_pipex_read_input(const char * file_name)
{
	int		status;
	int 	fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error_print_errno();
	line = "";
	while ( line != NULL)
	{
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL)
		{
			ft_putstr_fd(line, S);
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

static	void ft_execute_commands(t_params params, const char **path, \
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
*/

static t_bool	ft_read_input_file(const char *filename
{
	int		fd;
	char	*line;

	fd = open(filename,O_RDONLY);
	if (fd < 0)
		return (FALSE);
	line = filename;
	while (line != NULL)
	{
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL)
			write(STDOUT_FILENO, line, ft_strlen(line));
	}
	return (TRUE);
}

static t_bool	ft_write_output_file(const char *filename)
{
	int 	fd;
	char	*line;

	fd = open(filename, O_WRONLY | O_CREAT , 744);
	if (fd < 0)
		return (FALSE);
	line = filename;
	while (line != NULL)
	{
		line = ft_get_next_line_many_fds(STDIN_FILENO);
		if (line !=NULL)
			write(fd, line, ft_strlen(line));
	}
	close (fd);
	return (TRUE);
}

char	**ft_process_parse_cmd2(const char *command)
{
	char	**splitted_str;
	splitted_str = ft_split(command, ' ');
	if (splitted_str == NULL)
		return (NULL);
	return (splitted_str);	
}

void    ft_process_execute2(t_params args, size_t num_proc, const char **path)
{	
	char    *exec;
	char    *path;
	size_t	i;
	char	**splitted_cmd;

	splitted_cmd  = ft_process_parse_cmd2(args.argv[num_proc]);	
	i = 0;
	while (path[i] != NULL)
	{
		exec = ft_strjoin(path[i], splitted_cmd[0]);
		if(access(exec, X_OK) == 0)
		{
			if (execve(exec, (char * const *)splitted_cmd + 1,NULL) < 0)
				ft_error_print_errno();
			return ;
		}
		i++;
	}
	ft_ptr_free_matrix(splitted_cmd);
}


t_bool	ft_execute(t_params params, size_t i, const char **path)
{
	t_pipe	pipe;
	pid_t	pid;
	int		status;

	if (i == params.argc - 1)
		return (ft_write_output_file(params.argv[i]));
	pipe = ft_pipe_new();
	pid = fork();
	if(pid != 0)
	{
		close(pipe.rd_fd);
		if(pid < 0)
		{
			//ft_ptr_free_matrix(path);
			ft_error_print_errno();
			//exit(EXIT_FAILURE);
			return (FALSE);
		}
		dup2(pipe.wr_fd, STDOUT_FILENO);
		if (i == 1)
			ft_read_input_file(params.argv[i]);
		else
			ft_process_execute2(params, i, path);
		wait(&status);
		close(pipe.wr_fd);
	}
	else
	{
		close(pipe.wr_fd);
		dup2(pipe.rd_fd, STDIN_FILENO);
		ft_execute(params, i + 1 , path);
		close(pipe.rd_fd);		
	}
	return (TRUE);
}

/*
	if (i == 1)
	{
		fd = ft_open_input_file(params.argv[i]);
		if (fd < 0)
		{
			ft_error_print_errno();
			return (FALSE);
		}
	}
	if (i == params.argc - 1)
	{
		
	}

*/
int	main(int argc, char **argv, char *envp[])
{
	t_params		params;
	char			**path_folders;
	size_t          i;

	params = ft_utils_create_params(argc, argv, envp);
	if (params.argc <= 5)
	{
		ft_error_print_str("Error\nBad number of arguments\n");
		exit(EXIT_FAILURE);
	}
	path_folders = ft_env_get_path(params.envp);
	if (path_folders == NULL)
	{
		ft_error_print_str("Error\nError parsing environment\n");
		exit(EXIT_FAILURE);
	}
	ft_execute(params, 1, path_folders);
	ft_ptr_free_matrix(path_folders);
	return (0);
}

/*
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
*/