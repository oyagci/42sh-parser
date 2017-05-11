/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ln_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 12:52:34 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/28 17:27:07 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <getline/getline.h>
#include <termcap.h>

int				ln_putc(char c, t_line *line_info)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	if (line_info->x >= w.ws_col - 1)
	{
		tputs(tgetstr("do", NULL), 1, &ft_putc);
		line_info->x = 0;
		line_info->y += 1;
	}
	ft_putchar(c);
	line_info->x += 1;
	return (1);
}
