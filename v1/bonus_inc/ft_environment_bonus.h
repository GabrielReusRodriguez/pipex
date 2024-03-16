/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:28:54 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:27:13 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVIRONMENT_BONUS_H
# define FT_ENVIRONMENT_BONUS_H

typedef struct s_env
{
	char	**env;
	char	**path;
}	t_env;

t_env	ft_env_new(char *envp[]);

#endif