/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipelist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:13:24 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/13 23:45:01 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_cmd.h"
#include "ft_environment.h"
#include "ft_ptr.h"

static void	*ft_pipelist_push_cmd(t_list **list, char *arg, char **path, char **env)
{
	t_cmd	*cmd;
	t_list	*node;

	cmd = ft_cmd_new(arg, path, (const char **)env);
	if(cmd == NULL)
		return (NULL);
	node = ft_lstnew(cmd);
	if (node == NULL)
	{		
		ft_cmd_free(cmd);
		return (NULL);
	}
	ft_lstadd_back(list, node);
	return (node);
}

t_list	*ft_pipelist_create(char **argv, int argc, char **env)
{
	t_list	*list;
	size_t	i;
	char	**path;

	list = NULL;
	path = ft_env_getpath(env);
	i = 0;
	while (i < (size_t)argc - 1)
	{
		if (ft_pipelist_push_cmd(&list,argv[i], path, env) == NULL)
		{
			ft_ptr_free_matrix(path);
			ft_lstclear(&list, &ft_cmd_free);
			return (NULL);
		}
		i++;
	}
	ft_ptr_free_matrix(path);
	return (list);
}
