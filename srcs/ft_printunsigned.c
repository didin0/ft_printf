/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:01:11 by mabbadi           #+#    #+#             */
/*   Updated: 2023/05/10 12:37:09 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../Libft/libft.h"

int	len_nb(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		len++;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_unitoa(unsigned int nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = len_nb(n);
	str = (char *)ft_calloc(sizeof(char), (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}

int	ft_printunsigned(unsigned int nb)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_unitoa(nb);
	len = ft_printstr(num);
	free(num);
	return (len);
}
