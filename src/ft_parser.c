/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:17:00 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/23 17:07:14 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_type(const char *format, t_env *env)
{
	int	j;

	j = 0;
	while (env->lsttype[j] != '\0')
	{
		if (env->lsttype[j] == format[env->i])
			env->type = env->lsttype[j];
		j++;
	}
}

void	ft_check_modifier(const char *format, t_env *env)
{
	if (format[env->i] == 'h' && format[env->i + 1] != 'h')
		env->modifier = 1;
	if (format[env->i] == 'h' && format[env->i + 1] == 'h')
	{
		env->modifier = 2;
		env->i++;
	}
	if (format[env->i] == 'l' && format[env->i + 1] != 'l')
		env->modifier = 3;
	if (format[env->i] == 'l' && format[env->i + 1] == 'l')
	{
		env->modifier = 4;
		env->i++;
	}
	if (format[env->i] == 'j')
		env->modifier = 5;
	if (format[env->i] == 'z')
		env->modifier = 6;
	if (env->modifier == 0)
		env->i--;
	env->i++;
}

void	ft_check_width_precision(const char *format, t_env *env)
{
	while (ft_isdigit(format[env->i]) == 1)
	{
		env->width = env->width * 10 + (format[env->i] - 48);
		env->i++;
	}
	if (format[env->i] == '.')
	{
		env->i++;
		while (ft_isdigit(format[env->i]) == 1)
		{
			env->precision = env->precision * 10 + (format[env->i] - 48);
			env->i++;
		}
	}
}

void	ft_check_flags(const char *format, t_env *env)
{
	while (format[env->i] < 49 && format[env->i] != '.')
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

		printf("*%c*\n",format[env->i]);
		ft_check_flags(format, env);
		printf("**%c**\n",format[env->i]);
		ft_check_width_precision(format, env);
		printf("***%c***\n",format[env->i]);
		ft_check_modifier(format, env);
		printf("****%c****\n",format[env->i]);
		ft_check_type(format, env);
		printf("*****%c*****\n",format[env->i]);
}
