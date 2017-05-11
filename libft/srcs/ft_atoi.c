/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:02:44 by oyagci            #+#    #+#             */
/*   Updated: 2016/11/06 08:59:51 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	number;
	int	is_negative;

	number = 0;
	while (*(unsigned char *)str <= ' ')
		str += 1;
	if (*str == '-')
	{
		is_negative = -1;
		str += 1;
	}
	else if (*str == '+')
	{
		is_negative = 1;
		str += 1;
	}
	else
		is_negative = 1;
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str += 1;
	}
	return (number * is_negative);
}
