/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 23:01:38 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/03 20:48:03 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

t_params	ft_utils_create_params(int argc, char**argv, char *envp[])
{
	t_params	params;

	params.argc = argc;
	params.argv = argv;
	params.envp = envp;
	return (params);
}