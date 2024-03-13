/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:28:54 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/12 19:24:27 by gabriel          ###   ########.fr       */
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