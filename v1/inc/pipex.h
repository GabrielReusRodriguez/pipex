/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:03:54 by cclaude           #+#    #+#             */
/*   Updated: 2024/03/06 00:12:55 by gabriel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/*
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
*/

# define PIPE_READ_FD 0
# define PIPE_WRITE_FD 1

# define INFILE 0
# define OUTFILE 1

char	*path_join (char *path, char *bin);
int		str_ncmp (char *str1, char *str2, int n);
int		str_ichr (char *str, char c);
char	*str_ndup (char *str, unsigned int n);
char	**str_split (char *str, char sep);

char	**ft_env_getpath (char **env);
#endif