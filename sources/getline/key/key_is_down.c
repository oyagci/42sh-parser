/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:05:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 11:14:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				key_is_down(unsigned int const buffer)
{
	return (buffer == 0x00425b1b);
}
