/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 00:33:20 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/12 19:21:06 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_ptr_free_matrix(char **matrix)
{
	size_t	i;

	if (matrix != NULL)
	{
		i = 0;
		while (matrix[i] != NULL)
		{
			free (matrix[i]);
			i++;
		}
		free (matrix);
	}
	return (NULL);
}

void	*ft_ptr_free_ptr(void *ptr)
{
	if (ptr != NULL)
		free (ptr);
	return (NULL);
}
