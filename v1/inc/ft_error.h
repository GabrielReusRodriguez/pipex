/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 22:19:54 by greus-ro          #+#    #+#             */
/*   Updated: 2024/03/16 22:26:50 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

void	ft_error_print_errno(const char *msg);
void	ft_error_print_errno_and_exit(const char *msg, int exit_status);
void	ft_error_print_str(const char *str);
void	ft_error_print_str_and_exit(const char *str, int exit_status);
void	ft_error_print_code(int code);

#endif