/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:17:00 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/22 20:39:33 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	ft_check_modifier(const char *format, t_env *env)
{

}

void	ft_check_width_precision(const char *format, t_env *env)
{
	while (ft_isdigit(format [env->i] == 1))
	{
		env->width = env->width * 10 + (env->width - 48);
		env->i++;
	}
	if (format[env->i] == '.')
	{
		while (ft_isdigit(format [env->i] == 1))
		{
			env->precision = env->precision * 10 + (env->precision - 48);
			env->i++;
		}
	}
}

void	ft_check_flags(const char *format, t_env *env)
{
	while(ft_isdigit(format[env->i]) == 0)
	{
		if (format[env->i] == '0')
			env->flags[0] = 1;
		if (format[env->i] == '#')
			env->flags[1] = 1;
		if (format[env->i] == '+')
			env->flags[2] = 1;
		if (format[env->i] == '-')
			env->flags[3] = 1;
		if (format[env->i] == ' ')
			env->flags[4] = 1;
			env->i++;
	}
}

void	ft_check_all_flags(const char *format, t_env *env)
{
	while(format[env->i] != '%' || format[env->i] != '\0')
	{
		ft_check_flags(format, env);
		ft_check_width_precision(format, env);
		ft_check_modifier(format, env);
	}
}

int		ft_parser(const char *format, t_env *env, va_list ap)
{
	while (format[env->i] != '\0')
	{
		if (format[env->i] == '%')
		{
			env->i++;
			ft_clean_env(env);
			ft_check_all_flags(format, env);
			ft_doit();
		}
		env->i++;
	}
	return (0);
}
