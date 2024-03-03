/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:28:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/03 20:47:53 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

typedef unsigned char   t_bool;

typedef struct s_params
{
	int argc;
	char **argv;
	char **envp;
}   t_params;

# define TRUE 1
# define FALSE 0

t_params	ft_utils_create_params(int argc, char**argv, char *envp[]);


#endif