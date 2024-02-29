/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 01:31:03 by gabriel           #+#    #+#             */
/*   Updated: 2024/02/29 00:29:19 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_ptr.h"
#include "libft.h"

static char *ft_env_add_slash(char *folder)
{
	char	*path;
	
	printf("folder: _%s_\n",folder);
	path = ft_strjoin(folder, "/");
	free (folder);
	return (path);
}

static char	**ft_env_split_path(const char *path)
{
	char    **folders;
	char    *aux;
	size_t  i;

	folders = ft_split(path,':');
	if (folders == NULL)
		return (NULL);
	i = 0;
	while (folders[i] != NULL)
	{
		aux = folders[i];
		aux = ft_env_add_slash(aux);
		if (aux == NULL)
		{
			ft_ptr_free_matrix(folders);
			return (NULL);
		}
		folders[i] = aux;
		i++;
	}
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
				if(env == NULL)
					return (NULL);
				path = ft_env_split_path(env);
				free (env);
				return (path);
			}
			i++;
		}
	}
	return (NULL);
}
