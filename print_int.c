/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kepouliq <kepouliq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:46:47 by kepouliq          #+#    #+#             */
/*   Updated: 2024/06/04 18:53:01 by kepouliq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	length_nb(int nb)
{
	int		len;
	long	nbr;

	len = 1;
	nbr = nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		len += 1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len += 1;
	}
	return (len);
}

int	put_int(int nb)
{
	long	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		put_int(nbr / 10);
	ft_putchar(nbr % 10 + '0');
	return (length_nb(nb));
}
