/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:23:52 by mabbadi           #+#    #+#             */
/*   Updated: 2023/05/10 13:23:17 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_intlen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_printhex(unsigned int x, char x_or_x)
{
	char	*string;
	char	*base_character;
	int		i;
	int		ret;

	i = ft_intlen(x);
	ret = i;
	if (x_or_x == 'X')
		base_character = "0123456789ABCDEF";
	else
		base_character = "0123456789abcdef";
	if (x == 0)
		return (ft_printchar('0'));
	string = malloc(sizeof(char) * i + 1);
	if (!string)
		return (-1);
		string[i] = 0;
	while (x != 0 && i > 0)
	{
		string[i - 1] = base_character[x % 16];
		x = x / 16;
		i--;
	}
	ft_printstr(string);
	free(string);
	return (ret);
}
