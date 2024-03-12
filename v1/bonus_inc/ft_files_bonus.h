/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:40:12 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 19:24:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_BONUS_H
# define FT_FILES_BONUS_H

# define INFILE 0
# define OUTFILE 1

int		ft_file_open(char *filename, int mode);
void	ft_file_close(int fdin, int fdout);

#endif