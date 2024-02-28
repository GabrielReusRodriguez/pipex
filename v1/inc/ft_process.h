/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:38:16 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/28 22:54:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESS_H
# define FT_PROCESS_H

# include <sys/types.h>
# include "ft_pipe.h"
typedef struct s_process
{
	pid_t   pid;
	t_pipe  pipe_in;
	t_pipe  pipe_out;
	char    **path;
	char    *exec;
	char    **params;
}   t_process;

void		ft_process_execute(t_process *proc);
t_process	*ft_process_new(const char *command, const char **path, \
				t_pipe in, t_pipe out);
void		ft_process_destroy(void	*ptr);

#endif