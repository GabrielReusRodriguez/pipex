/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:00:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 19:24:42 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_BONUS_H
# define FT_EXEC_BONUS_H

# include "ft_environment_bonus.h"

int		ft_exec_redir_and_cmd(char *cmd, t_env env, int fdout);
void	ft_exec_cmd(char *cmd, t_env env);

#endif