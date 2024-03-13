/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:24:50 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/13 23:32:40 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CMD_H
# define FT_CMD_H

# include <stddef.h>
# include "sys/types.h"

typedef	struct s_cmd
{
	int		pipe[2];
	char	*cmd;
	char	**args;
	char	**env;
	pid_t	pid;
	int		status;
}	t_cmd;

void	ft_cmd_init(t_cmd	*cmd);
void	ft_cmd_free(void	*cmd);
t_cmd	*ft_cmd_new(char *argv, char **path, const char **env);

#endif