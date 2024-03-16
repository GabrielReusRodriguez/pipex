/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:42:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:27:24 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FD_BONUS_H
# define FT_FD_BONUS_H

# define PIPE_READ_FD 0
# define PIPE_WRITE_FD 1
# define PIPE_ALL_FD 2

# define NO_FD -1

# include "ft_utils_bonus.h"

typedef struct s_fds
{
	int	in;
	int	out;
}	t_fds;

t_bool	ft_fd_pipe_close(int fd[2], int which_fd);
void	ft_fd_check(int fdin, int fdout);
void	ft_fd_dups(int fdin, int fdout);

#endif