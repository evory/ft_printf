/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 04:38:15 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/06 14:58:14 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* gestion des flags | (*form) = travail sur pointeur pour modifier valeur */

static void ft_width(const char *format, t_form **form, int *i)
{
	while (ft_isdigit(format[*i]) == 1)
	{
		(*form)->width = (*form)->width * 10 + (format[*i] - 48);
		(*i)++;
	}
}

void	ft_flags_width_precision(const char *format, t_form **form, int *i)
{
	while (ft_isalpha(format[*i] != 1))
	{
		if (format[*i + 1] == '-')
			(*form)->flags[0] = 1;
		if (format[*i + 1] == '+')
			(*form)->flags[1] = 1;
		if (format[*i + 1] == ' ')
			(*form)->flags[2] = 1;
		if (format[*i + 1] == '0')
			(*form)->flags[3] = 1;
		if (format[*i + 1] == '#')
			(*form)->flags[4] = 1;
		if (ft_isdigit(format[*i] == 1))
			ft_width(format, form, i);
		(*i)++;
	}
}

/* check la balise % */

int		ft_parser(const char *format, t_form **form)
{
	int i;

	i = 0;
	while (format[i])
	{
		printf("i = %d\n", i);
		if (format[i] == '%' && format[i + 1] != '%')
			ft_flags_width_precision(format, form, &i);
		i++;
	}
	return (0);
}
