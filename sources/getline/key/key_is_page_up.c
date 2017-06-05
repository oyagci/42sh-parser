/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_page_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 14:04:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 11:14:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				key_is_page_up(unsigned int const buffer)
{
	unsigned int const	value = 0x7e355b1b;

	return (buffer == value);
}
