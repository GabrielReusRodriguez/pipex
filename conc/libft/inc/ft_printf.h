/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greus-ro <greus-ro@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:57 by greus-ro          #+#    #+#             */
/*   Updated: 2024/02/02 01:57:07 by greus-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

typedef struct s_format
{
	unsigned char	b_minus;
	unsigned char	b_plus;
	unsigned char	b_space;
	unsigned char	b_zero;
	unsigned char	b_hash;
	unsigned char	b_precision;
	size_t			n_precision;
	size_t			n_width;
	char			c_data_type;
	size_t			len;
}	t_format;

int			ft_printf(char const *str, ...);
char		*ft_printf_char(va_list argp, t_format *format);
char		*ft_printf_str(va_list argp, t_format	*format);
char		*ft_printf_ptr(va_list argp, t_format	*format);
char		*ft_printf_dec(va_list argp, t_format	*format);
char		*ft_printf_int(va_list argp, t_format	*format);
char		*ft_printf_usgn(va_list argp, t_format	*format);
char		*ft_printf_low_hex(va_list argp, t_format	*format);
char		*ft_printf_up_hex(va_list argp, t_format	*format);
char		*ft_printf_htoa(unsigned long u_number, unsigned int up_case, \
				t_format *format);
char		*ft_printf_percent(t_format *format);

void		ft_load_format_default(t_format *format);
t_format	*ft_load_format(const char *str);

char		*ft_apply_sign_format(char *str, int positive, t_format *format);
char		*ft_apply_hash_format(char *str, unsigned long n, t_format *format);
char		*ft_apply_width(char *str, t_format *format);

#endif