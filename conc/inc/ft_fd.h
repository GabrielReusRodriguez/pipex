/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:42:29 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/09 22:12:36 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FD_H
# define FT_FD_H

# define PIPE_READ_FD 0
# define PIPE_WRITE_FD 1
# define PIPE_ALL_FD 2

# define NO_FD -1

# include "ft_utils.h"

t_bool	ft_fd_pipe_close(int fd[2], int which_fd);

#endif