/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long_long_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:32:21 by juthomas          #+#    #+#             */
/*   Updated: 2017/04/01 04:47:30 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

int		ft_strlen_error_long_long_int(char *base)
{
	int			i;
	int			j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (i <= 1)
		return (1);
	return (i);
}

void	limite_long_long_int(long long int n, char *base, int u)
{
	if (n < 0)
	{
		ft_putchar_printf('-');
		n = n * -1;
	}
	if (n >= u)
		limite_long_long_int(n / u, base, u);
	ft_putchar_printf(base[(n % u)]);
}

void	ft_putnbr_base_long_long_int_remix(unsigned long long int nbr,
		char *base)
{
	int						u;

	u = ft_strlen_error_long_long_int(base);
	if (u > 1)
	{
		if ((nbr / u) > 0)
			ft_putnbr_base_long_long_int_remix(nbr / u, base);
		ft_putchar_printf(base[(nbr % u)]);
	}
}

void	ft_putnbr_base_long_long_int(long long int nbr, char *base)
{
	int						u;
	unsigned long long int	n;

	u = ft_strlen_error_long_long_int(base);
	if (u > 1)
	{
		if (nbr < 0)
			nbr = nbr * -1;
		n = (long long int)nbr;
		ft_putnbr_base_long_long_int_remix(n, base);
	}
}
