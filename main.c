/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:59:58 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/06 14:58:08 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(int argc, char const *argv[])
{
	char	*tests;
	char	testc;
	int		testd;
	t_form	*form;

	tests = "Bonjour";
	testc = 'c';
	testd = 42;

	ft_printf("coucou\n");
	printf("||coucou||\n");
	ft_printf("%c\n", testc);
	printf("||%c||\n", testc);

	//ft_printf("%d'\n", form->width);
	printf("%200d'\n", testd);
	printf("%d\n\n", printf("base test|%s|\n", tests));

/*	ft_printf("%s\n", tests);
	printf("%s\n",tests);
	ft_printf("", );
	printf("%s\n", );
	ft_printf("", );
	printf("%s\n", );
	ft_printf("", );
	printf("%s\n", );
	ft_printf("", );
	printf("%s\n", );
	ft_printf("", );
	printf("%s\n", );
	ft_printf("", );
	printf("%s\n", );
	ft_printf("", );
	printf("%s\n", );
	ft_printf("", );
	printf("%s\n", ); */
	return (0);
}
