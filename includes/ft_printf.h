/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:49:46 by bbrandt           #+#    #+#             */
/*   Updated: 2017/01/26 04:51:49 by bbrandt          ###   ########.fr       */
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
	int				presision;
	int				modifier;
	struct s_form	*next;
}					t_form;

int		ft_printf(const char *format, ...);
t_form	*ft_init_form(void);
int		ft_parser(const char *format, t_form **form);
void	ft_flags_width_precision(const char *format, t_form **form, int *i);

#endif
