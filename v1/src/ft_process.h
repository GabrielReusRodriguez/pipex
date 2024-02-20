/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:58:39 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/18 23:09:14 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESS_H
# define FT_PROCESS_H

# include <sys/types.h>

typedef struct s_process
{
	int		fd_read;
	int		fd_write;
	pid_t	pid;
	char	*command;
}	t_process;

#endif
