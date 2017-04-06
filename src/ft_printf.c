/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:02:02 by bbrandt           #+#    #+#             */
/*   Updated: 2017/04/06 22:21:19 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parser(const char *format, t_env *env, va_list ap)
{
	env->size = env->i;
	while (format[env->i] != '\0')
	{
		while (format[env->size] != '%') // Boucle à revoir
			{
				ft_putchar(format[env->size]);
				env->size++;
			}
		if (format[env->i] == '%')
		{
			ft_prinfarg(env);
			env->i++;
			ft_clean_env(env);
			ft_check_all_flags(format, env);
			ft_doit(env, ap);
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
	printf("\n");
	printf("env->i    = [%d]\n", env->i);
	printf("env->size = [%d]\n", env->size);
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
