/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:38:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/10 23:52:10 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft_error.h"
#include "ft_files.h"

int	ft_file_open(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK) == -1)
		{
			return (-1);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644));
}

void	ft_file_close(int fdin, int fdout)
{
	if (fdin >= 0)
		close(fdin);
	if (fdout >= 0)
		close(fdout);
}
