/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:38:16 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 22:58:36 by gabriel          ###   ########.fr       */
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

void		ft_process_execute(t_process *process, size_t num_proc, \
				t_main_params params);
t_process	*ft_process_new(const char *command, const char **path, \
				t_pipe *pipes, size_t i);
void		ft_process_destroy(void	*ptr);

#endif