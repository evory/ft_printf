/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 04:38:15 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/17 05:29:14 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_modifier(const char *format, t_form **form, int *i)
{
	if (format[*i] == 'h' && format[*i + 1] != 'h')
		(*form)->modifier = 1;
	if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		(*form)->modifier = 2;
		(*i)++;
	}
	if (format[*i] == 'l' && format[*i + 1] != 'l')
		(*form)->modifier = 3;
	if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		(*form)->modifier = 4;
		(*i)++;
	}
	if (format[*i] == 'j')
		(*form)->modifier = 5;
	if (format[*i] == 'z')
		(*form)->modifier = 6;
	(*i)++;
}

static void	ft_precision(const char *format, t_form **form, int *i)
{
	(*i)++;
	while (ft_isdigit(format[*i]) == 1 && format[*i])
	{
		(*form)->precision = (*form)->precision * 10 + (format[*i] - 48);
		(*i)++;
	}
	(*i)--;
}

static void	ft_width(const char *format, t_form **form, int *i)
{
	while (ft_isdigit(format[*i]) == 1 && format[*i])
	{
		(*form)->width = (*form)->width * 10 + (format[*i] - 48);
		(*i)++;
	}
}

void		ft_flags_width_precision(const char *format, t_form **form, int *i)
{
	(*i)++;
	while (ft_isalpha(format[*i]) != 1 && format[*i])
	{
		if (format[*i] == '-')
			(*form)->flags[0] = 1;
		if (format[*i] == '+')
			(*form)->flags[1] = 1;
		if (format[*i] == ' ')
			(*form)->flags[2] = 1;
		if (format[*i] == '0')
			(*form)->flags[3] = 1;
		if (format[*i] == '#')
			(*form)->flags[4] = 1;
		if (ft_isdigit(format[*i]) == 1 && format[*i] != '0')
			ft_width(format, form, i);
		if (format[*i] == '.')
			ft_precision(format, form, i);
		(*i)++;
	}
	(*i)--;
}

int			ft_parser(const char *format, t_form **form)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			ft_lsadd(form, ft_new_form());
			ft_flags_width_precision(format, form, &i);
			ft_modifier(format, form, &i);
			ft_get_types(format, form, &i);
		}
		ft_putchar(format[i]);
		i++;
	}
	return (i);
}
