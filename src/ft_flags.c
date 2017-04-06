/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 17:19:42 by bbrandt           #+#    #+#             */
/*   Updated: 2017/04/06 16:29:40 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flags3(t_env *env, va_list ap) // - justifié à gauche et complété à droite par des espaces
{

}

void	ft_flags2(t_env *env, va_list ap) // + les résultats commencent toujours par le signe + ou -
{
	if (ap < 0)
		ft_putchar('-');
	else
		ft_putchar('+');
}

void	ft_flags1(t_env *env, va_list ap) // #
{

}

void	ft_flags0(t_env *env, va_list ap) // 0
{

}

void ft_flags(t_env *env, va_list ap)
{
	if (env->flags[0] == 1)
		ft_flags0(env, ap);
	if (env->flags[1] == 1)
		ft_flags1(env, ap);
	if (env->flags[2] == 1)
		ft_flags2(env, ap);
	if (env->flags[3] == 1) // A FAIRE A LA FIN ET PAS ICI ?
		ft_flags3(env, ap);
	if (env->flags[4] == 1)
		{
			if (ap < 0)
				ft_putchar('-');
		}
}
