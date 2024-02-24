/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:31:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/24 01:36:58 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ptr.h"
#include "libft.h"

static char    **ft_env_split_path(const char *path)
{
    char    **folders;

    folders = ft_split(path,':');
    return (folders);
}

char	**ft_env_get_path(char *envp[])
{
	char	**path;
	char	*env;
	size_t	i;
	size_t	len;

	i = 0;
	if (envp != NULL)
	{
		while (envp[i] != NULL)
		{
			if (ft_strncmp(envp[i],"PATH=", 5) == 0)
			{
				len = ft_strlen(envp[i]);
				env = ft_substr(envp[i],4,len - 4);
                if(len == NULL)
                    return (NULL);
                path = ft_env_split_path(env);
                if (path == NULL)
                    return (ft_ptr_free_ptr(env));
                return (path);
			}
			i++;
		}
	}
	return (NULL);
}
