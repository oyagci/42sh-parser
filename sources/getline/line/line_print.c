/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 16:58:00 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 14:33:07 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <getline/getline.h>
#include <libft.h>
#include <sys/ioctl.h>
#include <unistd.h>

void			ln_reset_cursor_position(t_line *line)
{
	size_t	i;

	i = 0;
	while (i < line->y)
	{
		tputs(tgetstr("up", NULL), 1, &ft_putc);
		i += 1;
	}
	tputs(tgetstr("cr", NULL), 1, &ft_putc);
	line->y = 0;
	line->x = 0;
}

void			ln_increment_cursor(t_line *line)
{
	struct winsize	w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	if (line->x >= w.ws_col - 1)
	{
		tputs(tgetstr("do", NULL), 1, &ft_putc);
		line->x = 0;
		line->y += 1;
	}
	tputs(tgetstr("nd", NULL), 1, &ft_putc);
	line->x += 1;
}

void			ln_putcursor(t_line *line)
{
	size_t	i;

	ln_reset_cursor_position(line);
	i = 0;
	while (i <= line->index + 1)
	{
		ln_increment_cursor(line);
		i += 1;
	}
}

void			line_print(t_line *line)
{
	ln_reset_cursor_position(line);
	tputs(tgetstr("cd", NULL), 1, &ft_putc);
	ln_putstr("$ ", line);
	ln_putstr(line->content, line);
	ln_putcursor(line);
}
