/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:26:08 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:21:54 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_BONUS_H
# define FT_UTILS_BONUS_H

typedef unsigned char	t_bool;

# define TRUE 1
# define FALSE 0

char	*ft_utils_which(char **cmd_args, char **path);
int		ft_strcmp(const char *str1, const char *str2);

#endif