/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:02:02 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/23 17:07:10 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parser(const char *format, t_env *env, va_list ap)
{
	while (format[env->i] != '\0')
	{
		// printf("***%c***\n",format[env->i]);
		if (format[env->i] == '%')
		{
			env->i++;
			ft_clean_env(env);
			ft_check_all_flags(format, env);
			// ft_doit();
		}
		env->i++;
	}
	return (0);
}

int		ft_printf(const char * format, ...)
{
	va_list ap;
	t_env	*env;
	int		ret;

	va_start(ap ,format);
	env = ft_init_env();
	ret = ft_parser(format, env , ap);
	ft_prinfarg(env);
	return (ret);
}

void ft_prinfarg(t_env *env)
{
	printf("env->i    = [%d]\n", env->i);
	printf("flag[0]   = [%d]\n", env->flags[0]);
	printf("flag[1]   = [%d]\n", env->flags[1]);
	printf("flag[2]   = [%d]\n", env->flags[2]);
	printf("flag[3]   = [%d]\n", env->flags[3]);
	printf("flag[4]   = [%d]\n", env->flags[4]);
	printf("width     = [%d]\n", env->width);
	printf("precision = [%d]\n", env->precision);
	printf("modifier  = [%d]\n", env->modifier);
	printf("type      = [%c]\n", env->type);
}
