/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:56:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/21 00:05:08 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "ft_pipe.h"
#include "ft_error.h"
#include "ft_get_next_line.h"
#include "libft.h"


static void	ft_pipex_read_input(const char * file_name, pid_t pid_soon,t_pipe _pipe)
{
	int		status;
	int 	fd;
	char	*line;
	//size_t	len;

	close (_pipe.rd_fd);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_error_print_code(errno);
		exit(EXIT_FAILURE);
	}
	line = "";
//	dup2(_pipe.wr_fd, 1);
	while ( line != NULL)
	{
		line = ft_get_next_line_many_fds(fd);
		if (line != NULL)
		{
			//len = ft_strlen(line);
			//write(_pipe.wr_fd, line,len);
			ft_putstr_fd(line, _pipe.wr_fd);
			free(line);
		}
	}
	close(fd);
	close(_pipe.wr_fd);
	printf("wating...\n");
	waitpid(pid_soon, &status, 0);
	printf("FIN wating...\n");
}

static void	ft_pipex_write_output(const char * file_name,t_pipe _pipe)
{
	int 	fd;
	char	*line;

	close (_pipe.wr_fd);
	fd = open(file_name, O_WRONLY | O_CREAT, 744);
	if (fd < 0)
	{
		ft_error_print_code(errno);
		exit(EXIT_FAILURE);
	}
	line = "";
//	dup2(_pipe.wr_fd, 1);
	while ( line != NULL)
	{
		line = ft_get_next_line_many_fds(_pipe.rd_fd);
		if (line != NULL)
		{
			ft_putstr_fd(line, fd);
			free(line);
		}
	}
	close(fd);
	close(_pipe.rd_fd);
}

static void ft_pipex_execute_command(char **argv, int command, \
				int total_commands, t_pipe _pipe)
{
	char	*line;

	command = command;
	total_commands = total_commands;
	close (_pipe.wr_fd);
	line= argv[0];
	//dup2(_pipe.rd_fd, 1);
	while (line != NULL)
	{
		line = ft_get_next_line_many_fds(_pipe.rd_fd);
		//line = ft_get_next_line_many_fds(1);
		if(line != NULL)
		{
			printf("PRoceso hijo valor del string: %s",line);
			free (line);
		}
	}
	close(_pipe.rd_fd);
	printf("FIN\n");
	
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	t_pipe	_pipe;

	if(argc < 2)
	{
		ft_error_print_str("Bad  number of arguments\n");
		exit(EXIT_FAILURE);
	}
	_pipe = ft_pipe_new();
	pid = fork();
	if ( pid == -1)
	{
		ft_error_print_code(errno);
		exit(EXIT_FAILURE);
	}
	if(pid == 0) //Proceso Hijo
		ft_pipex_execute_command(argv, 1, argc, _pipe);
	else //Proceso padre
		ft_pipex_read_input(argv[1], pid, _pipe);
	return (0);
}