/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:00:09 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:26:52 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXEC_H
# define FT_EXEC_H

# include "ft_environment.h"

int		ft_exec_redir_and_cmd(char *cmd, t_env env, int fdout);
void	ft_exec_cmd(char *cmd, t_env env);

#endif