/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:48:51 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:27:12 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHILD_BONUS_H
# define FT_CHILD_BONUS_H

# include "ft_environment_bonus.h"

void	ft_child_execute(int pipefd[2], char *cmd, t_env env, int fdout);

#endif