/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:57:23 by mabbadi           #+#    #+#             */
/*   Updated: 2023/05/10 13:23:09 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_longlen(unsigned long long nb)
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

int	ft_printptr(unsigned long long x)
{
	char	*string;
	int		i;
	int		ret;

	i = ft_longlen(x);
	ret = i;
	if (x == 0)
		return (ft_printchar('0'));
	string = malloc(sizeof(char) * i + 1);
	if (!string)
		return (-1);
	string[i] = 0;
	while (x != 0 && i > 0)
	{
		string[i - 1] = "0123456789abcdef"[x % 16];
		x = x / 16;
		i--;
	}
	ft_printstr(string);
	free(string);
	return (ret);
}
