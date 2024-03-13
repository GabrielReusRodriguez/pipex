/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:40:51 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/13 23:45:28 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_cmd.h"
#include "ft_utils.h"
#include "ft_ptr.h"
#include "ft_environment.h"

void	ft_cmd_init(t_cmd	*cmd)
{
	cmd->pipe[0] = -1;
	cmd->pipe[1] = -1;
	cmd->status = -1;
	cmd->pid = -1;
	cmd->cmd = NULL;
	cmd->args = NULL;
}

void	ft_cmd_free(void	*ptr)
{
	size_t	i;
	t_cmd	*cmd;

	cmd = (t_cmd *)ptr;
	if (cmd != NULL)
	{
		if (cmd->cmd != NULL)
			free (cmd->cmd);
		i = 0;
		if (cmd->args != NULL)
		{
			while (cmd->args[i] != NULL)
			{
				free (cmd->args[i]);
				i++;
			}
			free (cmd->args);
		}
		free (cmd);
	}
}

t_cmd	*ft_cmd_new(char *argv, char **path, const char **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (NULL);
	ft_cmd_init(cmd);
	cmd->args = ft_split(argv, ' ');
	if (cmd->args == NULL)
	{
		ft_cmd_free(cmd);
		return (NULL);
	}
	cmd->cmd = ft_utils_which(cmd->args, path);
	if (cmd->cmd == NULL)
	{
		ft_cmd_free(cmd);
		return (NULL);
	}
	cmd->env = (char **)env;
	return (cmd);
}



/*
void	ft_cmd_init(t_cmd	*cmd);
void	ft_cmd_free(t_cmd	*cmds, size_t size);
void	ft_cmd_clear(t_cmd	*cmds);
t_cmd	*ft_cmd_new(char **argv, int argc, char **path);
*/