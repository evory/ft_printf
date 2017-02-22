/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:02:02 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/22 20:39:34 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char * format, ...)
{
	va_list ap;
	t_env	*env;
	int		ret;

	va_start(ap ,format);
	env = ft_init_env();
	ret  = ft_parser(format, env , ap);
	return (ret);
}
