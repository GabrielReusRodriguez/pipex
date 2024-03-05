/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:08:23 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/06 00:45:07 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#include "libft.h"
#include "ft_ptr.h"
#include "pipex.h"


int	ft_openfile (char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			perror("Error opening file:");
			/*
			write(STDERR, "pipex: ", 7);
			write(STDERR, filename, str_ichr(filename, 0));
			write(STDERR, ": No such file or directory\n", 28);
			*/
			return (STDIN_FILENO);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 644));
}

/*
char	*ft_getPath (char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i] == NULL)
		return (cmd);
	path = env[i] + 5;
	while (path && str_ichr(path, ':') > -1)
	{
		//dir = str_ndup(path, str_ichr(path, ':'));
		dir = ft_strdup(path, str_ichr(path, ':'));
		//bin = path_join(dir, cmd);
		bin = ft_strjoin(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (cmd);
}
*/



/*
char	*ft_getPath_cmd (char *cmd, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	char	**path_folders;

	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (env[i] == NULL)
		return (cmd);
	path = env[i] + 5;
	while (path && str_ichr(path, ':') > -1)
	{
		//dir = str_ndup(path, str_ichr(path, ':'));
		dir = ft_strdup(path, str_ichr(path, ':'));
		//bin = path_join(dir, cmd);
		bin = ft_strjoin(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (cmd);
}
*/
void	ft_exec_cmd (char *cmd, char **env, char **path)
{
	char	**cmd_args;
	char	*cmd_path;
	size_t	i;

	cmd_args = ft_split(cmd, ' ');
	if (cmd_args == NULL)
	{
		ft_putendl_fd("Error treating cmd", STDERR_FILENO);
		exit(EXIT_FAILURE);		
	}
	if (access(cmd_args[0], F_OK) == 0)
		cmd_path = cmd_args[0];
	else
	{
		i = 0;
		while(path[i] != NULL)
		{
			cmd_path = ft_strjoin(path[i], cmd_args[0]);
			ft_putendl_fd(cmd_path, STDERR_FILENO);
			if (access(cmd_path, F_OK) == 0)
				break;
			free(cmd_path);
			i++;
		}
		if (path[i] == NULL)
		{
			ft_ptr_free_matrix(cmd_args);
			exit(EXIT_FAILURE);			
		}
	}
	execve(cmd_path, cmd_args, env);
	free (cmd_path);
	ft_ptr_free_matrix(cmd_args);
	exit(EXIT_SUCCESS);
}

void	ft_exec_redir_and_cmd (char *cmd, char **env, int fdin, char **path)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid != 0)
	{
		close(pipefd[PIPE_WRITE_FD]);
		dup2(pipefd[PIPE_READ_FD], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[PIPE_READ_FD]);
		dup2(pipefd[PIPE_WRITE_FD], STDOUT_FILENO);
		if (fdin == STDIN_FILENO)
			exit(EXIT_SUCCESS);
		else
			ft_exec_cmd(cmd, env, path);
	}
}

int	main (int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;
	char	**path;

	if (argc == 5)
	{
		path = ft_env_getpath(env);
		fdin = ft_openfile(argv[1], INFILE);
		fdout = ft_openfile(argv[4], OUTFILE);
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		ft_exec_redir_and_cmd(argv[2], env, fdin, path);
		ft_exec_cmd(argv[3], env, path);
		close (fdin);
		close (fdout);
		ft_ptr_free_matrix(path);
	}
	else
		write(STDERR_FILENO, "Invalid number of arguments.\n", 29);
	return (1);
}