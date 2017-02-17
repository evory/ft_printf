/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 22:47:27 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/17 05:18:14 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
"h hh l ll j z | # 0 - + ' '" FLAGS
% [drapeaux] [largeur] [.precision] [modificateur] type
	ft_printf("blabla%[+-0# ][50][.42][h][d]);
*/

void	ft_printlst(t_form *form)
{
	t_form	*tmp;
	int		nb;

	nb = 0;
	tmp = form;
	while (tmp)
	{
		printf("\n---maillon %d---\n\n", nb);
		printf("types     = [%c]\n", tmp->types);
		printf("flags[0]  = [%d]\n", tmp->flags[0]);
		printf("flags[1]  = [%d]\n", tmp->flags[1]);
		printf("flags[2]  = [%d]\n", tmp->flags[2]);
		printf("flags[3]  = [%d]\n", tmp->flags[3]);
		printf("flags[4]  = [%d]\n", tmp->flags[4]);
		printf("width     = [%d]\n", tmp->width);
		printf("precision = [%d]\n", tmp->precision);
		printf("modifier  = [%d]\n", tmp->modifier);
		tmp = tmp->next;
		nb++;
	}
}

void	ft_get_types(const char *format, t_form **form, int *i)
{
	char	*types;
	int		j;

	j = 0;
	types = "sSpdDioOuUxXcC";
	while (types[j] != '\0')
	{
		if (format[*i] == types[j])
			(*form)->types = types[j];
		j++;
	}
}

void	ft_lsadd(t_form **alst, t_form *new)
{
	if (*alst)
		new->next = (*alst);
	*alst = new;
}

t_form	*ft_new_form(void)
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
	form->precision = 0;
	form->modifier = 0;
	form->next = NULL;
	return (form);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_form	*form;
	int		ret;

	form = NULL;
	va_start(ap, format);
	ret = ft_parser(format, &form);
	ft_printlst(form);
	printf("%d\n", ret);
	return (ret);
}
