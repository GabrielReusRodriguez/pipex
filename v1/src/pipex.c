/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:56:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/28 22:36:27 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include "ft_error.h"
#include "ft_pipe.h"
#include "ft_environment.h"
#include "libft.h"
#include "ft_process.h"

#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv, char *envp[])
{
	size_t		i;
	char		**path_folders;
	char		*environment;
	t_process	*process;

	
	if (argc != 5)
	{
		ft_error_print_str("Error\nBad number of argumennts");
		return (1);
	}
	path_folders = ft_env_get_path(envp);
	process = ft_process_new(argv[1], (const char **)path_folders, ft_pipe_new(), ft_pipe_new());
	ft_process_execute(process);
/*
	i = 2;
	while (i < (size_t)argc)
	{
		ft_execute_command(argv, i, argc);
	}
*/
	return (0);
}



/*
static t_list	*ft_create_process_list(char **commands, int total_commands, \
					const char **path)
{
	t_list		*cmd_list;
	t_list		*node;
	t_process	*proc;
	size_t		i;

	cmd_list = NULL;
	i = 0;
	while (i < total_commands)
	{
		proc = ft_process_new(commands[i], path);
		if (proc == NULL)
		{
			ft_lstclear(&cmd_list, &ft_process_destroy);
			ft_error_print_str("Error\nError creating t_process");
			return (NULL);
		}
		node = ft_lstnew(proc);
		if (node == NULL)
		{
			ft_process_destroy(proc);
			ft_lstclear(&cmd_list, &ft_process_destroy);
			ft_error_print_str("Error\nError creating t_process node");
			return (NULL);
		}
		ft_lstadd_back(&cmd_list, proc);
	}
	return(cmd_list);
}


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
*/
