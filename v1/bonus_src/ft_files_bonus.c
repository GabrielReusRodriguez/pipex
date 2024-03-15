/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:38:32 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/15 14:19:34 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft_error_bonus.h"
#include "ft_files_bonus.h"

/*
	oflag = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	EQUALS 0644
*/
int	ft_file_open(char *filename, int mode, const char *file_delimiter)
{
	int	oflag;

	oflag = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (mode == INFILE)
	{
		if (access(filename, R_OK) == -1)
			return (-1);
		return (open(filename, O_RDONLY));
	}
	else
	{
		if (file_delimiter == NULL)
			return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, oflag));
		else
		{
			if (access(file_delimiter, W_OK) == 0)
				return (open(filename, O_CREAT | O_WRONLY | O_APPEND, oflag));
			else
				return (open(filename, O_CREAT | O_WRONLY | O_TRUNC, oflag));
		}
	}
}

void	ft_file_close(int fdin, int fdout)
{
	if (fdin >= 0)
		close(fdin);
	if (fdout >= 0)
		close(fdout);
}
