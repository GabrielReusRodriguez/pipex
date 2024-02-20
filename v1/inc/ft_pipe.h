/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:05:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/20 23:16:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPE_H
# define FT_PIPE_H

typedef struct s_pipe
{
	int	rd_fd;
	int	wr_fd;
}	t_pipe;

t_pipe	ft_pipe_new(void);

#endif