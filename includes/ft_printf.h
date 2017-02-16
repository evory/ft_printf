/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:49:46 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/16 04:38:08 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_form
{
	int				types;
	int				flags[5];
	int				width;
	int				precision;
	int				modifier;
	struct s_form	*next;
}					t_form;

int		ft_printf(const char *format, ...);
t_form	*ft_new_form(void);
int		ft_parser(const char *format, t_form **form);
void	ft_flags_width_precision(const char *format, t_form **form, int *i);
void 	ft_lsadd(t_form **form, t_form *bite);
void 	ft_get_types(format, form, &i);

#endif
