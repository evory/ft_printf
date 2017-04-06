/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 16:39:04 by bbrandt           #+#    #+#             */
/*   Updated: 2017/04/06 17:46:17 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_type(t_env *env, va_list ap)
{

}

void ft_modifier(t_env *env, va_list ap)
{

}

void ft_precision(t_env *env, va_list ap)
{

}

/*void ft_width(t_env *env, va_list ap)
{
	if (env->flags[3] == 0)
	{
		if (ft_strlen(ap) < env->width)
		{
			while (ft_strlen(ap) < env->width)
				{
					ft_putchar(' ');
					env->width--;
				}
		}
	}
	if (ft_strlen(ap) > env->width)
	{
		env->width = env->width - (ft_strlen(ap) - env->width);
	}
}
*/

void	ft_doit(t_env *env, va_list ap)
{
	int nbflags;

	nbflags = env->flags[0] + env->flags[1] + env->flags[2] + env->flags[3]
	+ env->flags[4];
	if (nbflags > 0)
		ft_flags(env, ap);
	// if (env->width > 0)
		// ft_width(env, ap);
	if (env->precision > 0)
		ft_precision(env, ap);
	if (env->modifier > 0)
		ft_modifier(env, ap);
	if (env->type > 0)
		ft_type(env, ap);
}
