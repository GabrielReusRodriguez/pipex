/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:28:54 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/13 23:28:49 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENVIRONMENT_H
# define FT_ENVIRONMENT_H

typedef struct s_env
{
	char	**env;
	char	**path;
}	t_env;

t_env	ft_env_new(char *envp[]);
char	**ft_env_getpath(char **env);

#endif