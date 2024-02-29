/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:01:38 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 23:04:57 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

t_main_params	ft_utils_create_params(int argc, char**argv, char *envp[])
{
	t_main_params	params;

	params.argc = argc;
	params.argv = argv;
	params.envp = envp;
	return (params);
}