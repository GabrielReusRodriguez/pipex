/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 21:28:17 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 23:04:51 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

typedef unsigned char   t_bool;

typedef struct s_main_params
{
	int argc;
	char **argv;
	char **envp;
}   t_main_params;

# define TRUE 1
# define FALSE 0

t_main_params	ft_utils_create_params(int argc, char**argv, char *envp[]);


#endif