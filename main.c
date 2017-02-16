/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:59:58 by bbrandt           #+#    #+#             */
/*   Updated: 2017/02/16 04:33:00 by bbrandt          ###   ########.fr       */
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

	ft_printf("mon printf_c : [%0+49.3hhd]\n", test_c);
	//printf("printf : [%c]\n", test_c);
}
