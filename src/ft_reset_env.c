/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 20:07:27 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/22 20:39:30 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void ft_clean_env(t_env *env)
{
		env->flags[0] = 0;
		env->flags[1] = 0;
		env->flags[2] = 0;
		env->flags[3] = 0;
		env->flags[4] = 0;
		env->width = 0;
		env->precision = 0;
		env->modifier = 0;
		env->type = 0;
}

t_env	*ft_init_env(void)
{
	t_env	*env;

	if(!(env = malloc(sizeof(t_env))))
		return (NULL);
	env->lsttypes = "sSpdDioOuUxXcC%";
	env->lstmdfr = "hljz";
	env->i = 0;
	env->size = 0;
	env->flags[0] = 0;
	env->flags[1] = 0;
	env->flags[2] = 0;
	env->flags[3] = 0;
	env->flags[4] = 0;
	env->width = 0;
	env->precision = 0;
	env->modifier = 0;
	env->type = 0;
	return (env);
}
