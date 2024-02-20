/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:39:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/20 00:31:37 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "ft_error.h"
#include "ft_command.h"

/*
void	ft_command_execute_parent(int fds[2], const char **command, int num_command, int total_command)
{
//	close(fds[READ_FD]);
	if( num_command == 0)
	{
		//read file from read fd and write to write fd
	}
	else
	{
		//read from fd, execute command , write to write fd.
	}
}

void	ft_command_execute_child(int fds[2], const char **command, int num_command, int total_command)
{
//	close(fds[READ_FD]);
}
*/
/*
void	ft_command_execute(const char **commands, int total_commands)
{
	pid_t	pid;
	int		fds[2];

	//Obtengo los file descriptors....
	if(pipe(fds) < 0)
	{
		ft_error_print_code(errno);
		exit(1);
	}
	pid = fork();
	//CASO DE ERROR....
	if (pid ==  -1)
	{
		ft_error_print_code(errno);
		exit(1);
	}
	if (pid == 0)
	{
//		ft_command_execute_child(fds, commands, 1, total_commands);
		//hijo...
	}
	else
	{
		//Padre...
//		ft_command_execute_parent(fds, commands, 0, total_commands);		
	}


}
*/