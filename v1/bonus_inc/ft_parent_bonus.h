/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parent_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 22:23:58 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/15 14:16:01 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARENT_BONUS_H
# define FT_PARENT_BONUS_H

int		ft_parent_execute(int pipefd[2]);
int		ft_parent_get_last_child_status(size_t num_cmd);

#endif
