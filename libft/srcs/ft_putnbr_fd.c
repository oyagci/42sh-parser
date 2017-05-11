/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:49:31 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/05 15:55:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;
	char			nb_to_write;

	if (n < 0)
	{
		write(fd, "-", 1);
		u_n = -n;
	}
	else
		u_n = n;
	if (u_n > 9)
		ft_putnbr_fd(u_n / 10, fd);
	nb_to_write = '0' + (u_n % 10);
	write(fd, &nb_to_write, 1);
}
