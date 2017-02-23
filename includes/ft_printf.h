/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:49:46 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/23 17:07:11 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef	struct		s_env
{
	char			*lsttype;
	int				i;
	int				size;
	int				flags[5];
	int				width;
	int				precision;
	int				modifier;
	int				type;
}					t_env;

int					ft_printf(const char *format, ...);
int					ft_parser(const char *format, t_env *env, va_list ap);
t_env				*ft_init_env(void);
void				ft_clean_env(t_env *env);
void				ft_check_all_flags(const char *format, t_env *env);
void				ft_check_flags(const char *format, t_env *env);
void				ft_check_width_precision(const char *format, t_env *env);
void				ft_check_modifier(const char *format, t_env *env);
void 				ft_prinfarg(t_env *env);

#endif
