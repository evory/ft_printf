/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:59:58 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/20 16:48:24 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	main(int argc, char const *argv[])
{
	char	*test_s;
	char	test_c;
	int		test_d;

	test_c = 'c';
	test_s = "Bonjour";
	test_d = 42;
	int i;

	i = 42;
	ft_printf("%d%d\n", i, 43);
	// printf("%d\n", printf("%i\n", i));
}
