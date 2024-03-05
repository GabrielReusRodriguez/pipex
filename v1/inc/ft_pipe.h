/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:05:10 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/05 21:39:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPE_H
# define FT_PIPE_H

# include "ft_utils.h"

typedef struct s_pipe
{
	int	rd_fd;
	int	wr_fd;
}	t_pipe;

t_pipe	ft_pipe_new(void);
t_bool  ft_pipe_check(t_pipe pipe);

t_pipe	*ft_pipelist_create(size_t num_pipes);
void    *ft_pipelist_destroy(t_pipe *, size_t num_pipes);


#endif