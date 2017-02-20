/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:49:46 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/20 16:33:00 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef	struct		s_form
{
	char			types;
	int				flags[5];
	int				width;
	int				precision;
	int				modifier;
	struct s_form	*next;
}					t_form;

int					ft_printf(const char *format, ...);
t_form				*ft_new_form(void);
int					ft_parser(const char *format, t_form **form);
void				ft_flags_width_precision(const char *format, t_form **form,
					int *i);
void				ft_lsadd(t_form **form, t_form *new);
void				ft_get_types(const char *format, t_form **form, int *i);

#endif
