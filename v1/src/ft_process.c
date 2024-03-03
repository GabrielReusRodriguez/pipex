/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:39:08 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/03 23:00:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_process.h"
#include "ft_error.h"
#include "ft_pipe.h"
#include "libft.h"
#include "ft_ptr.h"

#include <stdio.h>


static char	**ft_process_parse_cmd(const char *command)
{
	char	**splitted_str;
	printf("parssed cmd = _%s_\n",command);
	splitted_str = ft_split(command, ' ');
	if (splitted_str == NULL)
		return (NULL);
	return (splitted_str);	
}

static t_process	*ft_process_create(void)
{
	t_process	*proc;
	
	proc = (t_process *)malloc(sizeof(t_process));
	if (proc == NULL)
	{
		ft_error_print_str("Error\nError at malloc of process");
		return (NULL);
	}
	proc->path = NULL;
	proc->exec  = NULL;
	proc->params = NULL;
	return (proc);
}

t_process	*ft_process_new(const char *command, const char **path, \
				t_pipe *pipes, size_t i)
{
	t_process	*proc;
	char		**splitted_command;

	splitted_command = ft_process_parse_cmd(command);
	if (splitted_command == NULL)
		return (ft_ptr_free_matrix(splitted_command));
	proc = ft_process_create();
	if (proc == NULL)
		return (NULL);
	proc->pipe_in = pipes[i * 2];
	proc->pipe_out = pipes[i * 2 + 1];
	proc->path = (char **)path;
	proc->params = splitted_command;
	proc->exec = splitted_command[0];
	return (proc);	
}

void		ft_process_destroy(void	*ptr)
{
	t_process	*proc;

	if (ptr != NULL)
	{
		proc = (t_process *)ptr;
//		if (proc->exec != NULL)
//			free (proc->exec);
		ft_ptr_free_matrix(proc->path);
		ft_ptr_free_matrix(proc->params);
		free (proc);
	}
}

void    ft_process_execute(t_process *process, size_t num_proc, \
			t_params params)
{	
	char    *exec;
	char    *path;
	size_t	i;

	i = 0;
	while (process->path[i] != NULL)
	{
		exec = ft_strjoin(process->path[i], process->exec);
		if(access(exec, X_OK) == 0)
		{
			if (execve(exec, (char * const *)process->params,NULL) < 0)
				ft_error_print_errno();
			return ;
		}
		i++;
	}
}


/*
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "ft_error.h"
#include "ft_command.h"
#include "libft.h"

#include <stdio.h>

static char **ft_get_env_vars(void)
{
	char	**envp;
	
	envp = malloc(2*sizeof(char *));
	if (envp == NULL)
	{
		ft_error_print_str("Error in malloc");
		exit(EXIT_FAILURE);	
	}
	envp[0] = ft_strjoin("PATH=/bin","");
	printf("PATH ; _%s_\n", envp[0]);
	envp[1] = NULL;
	if(envp[0] == NULL)
	{
		ft_error_print_errno();
		exit(EXIT_FAILURE);
	}
	return (envp);
}

void ft_execute_command(char **argv, int num_command, int total_command)
{
	char	**splited_command;
	char	*exec;
	char	**envp;


	char *args[]     = { "ls", "-l", "-a", NULL };
	char *env_args[] = { "PATH=/bin", "USER=me", NULL };

	execve(args[0], args, env_args);
	execvp(args[0], &args[0]);
	
	envp = ft_get_env_vars();
	splited_command = ft_split(argv[num_command], ' ');
	if (splited_command == NULL)
	{
		ft_error_print_str("Error reading args");
		exit(EXIT_FAILURE);
	}
	if (access(splited_command[0], F_OK | X_OK ) == -1)
	{
		ft_error_print_errno();
		exit(EXIT_FAILURE);
	}
	if (execve(splited_command[0] , splited_command, (char * const *)envp) == -1)
	{
		ft_error_print_errno();
		exit(EXIT_FAILURE);
	}
}
*/

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