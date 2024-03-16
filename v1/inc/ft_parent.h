/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:23:58 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:26:59 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARENT_H
# define FT_PARENT_H

int		ft_parent_execute(int pipefd[2]);
int		ft_parent_get_last_child_status(size_t num_cmd);

#endif