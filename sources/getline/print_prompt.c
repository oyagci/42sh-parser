/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 15:39:38 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/01 14:36:38 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <getline/getline.h>
#include <libft.h>

void			print_prompt(t_line *line_info)
{
	ft_putchar('\r');
	line_info->index = 0;
	line_info->len = 0;
	ln_putstr("hello$ ", line_info);
}
