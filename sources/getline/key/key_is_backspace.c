/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_is_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 14:58:48 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 11:14:51 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				key_is_backspace(unsigned int const buffer)
{
	return (buffer == 0x07f);
}
