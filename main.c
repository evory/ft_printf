/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:46:36 by bbrandt           #+#    #+#             */
/*   Updated: 2017/04/06 22:39:36 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int main(int argc, char const *argv[])
{
	int	i;
	char *str;

	str = "coucou";
	i = -42;
	ft_printf("TEST = %20.55c lolol%25.2d\n");
	printf("printf06.04 = [%7s]\n", str);
	printf("printf06.04 = [%5d]\n", i);

	return (0);
}
