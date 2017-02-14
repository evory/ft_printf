/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:47:27 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/06 14:58:07 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
"sSpdDioOuUxXcC"	TYPES
"."	précision
"10"	width
"h hh l ll j z | # 0 - + ' '" FLAGS

% [drapeaux] [largeur] [.precision] [modificateur] type

	ft_printf("blabla%[+-0# ][50][.42][h][d]);
*/

/* initialisation à 0 de la structure t_form et du tableau d'entier */

t_form	*ft_init_form(void)
{
	t_form	*form;

if (!(form = malloc(sizeof(t_form))))
		return (NULL);
	form->types = 0;
	form->flags[0] = 0;
	form->flags[1] = 0;
	form->flags[2] = 0;
	form->flags[3] = 0;
	form->flags[4] = 0;
	form->width = 0;
	form->presision = 0;
	form->modifier = 0;
	form->next = NULL;
	return (form);
}

/* parcour de [format],
detection '%',
ft_putchar du reste,
initialisation de va_start,
printf return le nombre de caractères lus */

int		ft_printf(const char * format, ...)
{
	va_list	ap;
	t_form	*form;
	int		ret;

	va_start(ap, format);
	form = ft_init_form();
	ft_parser(format, &form);
	return (ret);
}
