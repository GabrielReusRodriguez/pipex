/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipelist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:12:22 by gabriel           #+#    #+#             */
/*   Updated: 2024/03/13 23:14:31 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPELIST_H
# define FT_PIPELIST_H

# include "libft.h"

t_list	*ft_pipelist_create(char **argv, int argc, char **env);


#endif