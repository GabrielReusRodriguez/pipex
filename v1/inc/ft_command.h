/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:38:16 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/22 23:34:39 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMAND_H
# define FT_COMMAND_H

# define WRITE_FD 1
# define READ_FD 0

void ft_execute_command(char **argv, int num_command, int total_command);

#endif