/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_ctrl_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 15:41:10 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 11:14:51 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				key_is_ctrl_a(unsigned int const buffer)
{
	return (buffer == 0x01);
}
