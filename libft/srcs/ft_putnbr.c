/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:01:34 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/05 15:54:56 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	unsigned int	u_n;
	char			nb_to_write;

	if (n < 0)
	{
		write(1, "-", 1);
		u_n = -n;
	}
	else
		u_n = n;
	if (u_n > 9)
		ft_putnbr(u_n / 10);
	nb_to_write = '0' + (u_n % 10);
	write(1, &nb_to_write, 1);
}
