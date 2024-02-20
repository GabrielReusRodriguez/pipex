/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:38:16 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/18 23:28:20 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMMAND_H
# define FT_COMMAND_H

# define WRITE_FD 1
# define READ_FD 0

void ft_command_execute(const char **commands, int total_commands);


#endif