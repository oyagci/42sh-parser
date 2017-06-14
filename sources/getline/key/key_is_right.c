/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:04:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 11:14:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				key_is_right(unsigned int const buffer)
{
	unsigned int const	value = 0x435b1b;

	return (buffer == value);
}
