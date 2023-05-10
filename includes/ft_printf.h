/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbadi <mabbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:08:06 by mabbadi           #+#    #+#             */
/*   Updated: 2023/05/10 15:27:02 by mabbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
int		ft_formats(va_list args, const char format);
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int nbr);
int		ft_printunsigned(unsigned int nb);
int		len_nb(long nb);
int		ft_printhexmaj(unsigned int x);
int		ft_printhexmin(unsigned int x);
int		ft_printptr(unsigned long long x);
int		ft_printpercent(void);
char	*ft_unitoa(unsigned int nb);

#endif