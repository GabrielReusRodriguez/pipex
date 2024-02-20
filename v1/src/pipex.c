/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:56:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/20 01:09:21 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "ft_error.h"
#include "ft_get_next_line.h"
#include "libft.h"


int	main(int argc, char **argv)
{
	pid_t	pid;
	int		fds[2];
	int 	fd;
	char	*line;
	size_t	len;
	int		status;

	if(argc < 2)
	{
		ft_error_print_str("Bad  number of arguments\n");
		exit(EXIT_FAILURE);
	}
	argc = argc;
	pipe(fds);
	pid = fork();
	if ( pid == -1)
	{
		ft_error_print_code(errno);
		exit(1);
	}
	if(pid == 0)
	{
		//Proceso Hijo
		close (fds[1]);
		line= argv[0];
		while (line != NULL)
		{
			line = ft_get_next_line_many_fds(fds[0]);
			if(line != NULL)
				printf("PRoceso hijo valor del string: %s \n",line);
		}
		close(fds[0]);
		printf("FIN\n");

	}
	else
	{	
		//Proceso padre
		close (fds[0]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_error_print_code(errno);
			exit(EXIT_FAILURE);
		}
		line = argv[0];
		while ( line != NULL)
		{
			line = ft_get_next_line_many_fds(fd);
			if (line != NULL)
			{
				len = ft_strlen(line);
				write(fds[1],line,len);
				free(line);
			}
		}
		printf("FIN padre write\n");
		close(fd);
		close(fds[1]);
		printf("wait padre\n");
		waitpid(pid, &status, 0);
		printf("FIN padre\n");
	}
	printf("FINISIMO\n");
	return (0);
}