/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:48:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 20:44:32 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHILD_H
# define FT_CHILD_H

# include "ft_environment.h"

void	ft_child_execute(int pipefd[2], char *cmd, t_env env, int fdout);

#endif