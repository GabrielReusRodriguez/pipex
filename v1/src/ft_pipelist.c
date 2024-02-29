/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:35:14 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 23:18:11 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_pipe.h"

t_pipe	*ft_pipelist_create(size_t num)
{
	t_pipe	*v_pipes;
	size_t	i;

	v_pipes = (t_pipe *)malloc(num * sizeof(t_pipe));
	if (v_pipes == NULL)
		return (NULL);
	i = 0;
	while (i < num)
	{
		v_pipes[i] = ft_pipe_new();
		if (ft_pipe_check(v_pipes[i]) == FALSE)
		{
			ft_pipelist_destroy(v_pipes, i);
			return (NULL);
		}
		i++;
	}
	return (v_pipes);
}

void	*ft_pipelist_destroy(t_pipe *pipes, size_t num_pipes)
{
	size_t	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i].rd_fd);
		close(pipes[i].wr_fd);
		i++;
	}
	free (pipes);
	return (NULL);
}
