/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 10:12:09 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 10:29:34 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <termcap.h>
#include <string.h>

struct termios	g_tattr_save;

void		setraw(void)
{
	struct termios tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tcgetattr(STDIN_FILENO, &g_tattr_save);
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tattr.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}

void		unsetraw(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_tattr_save);
}

int			main(void)
{
	unsigned int	c = 0;
	unsigned int	line[128] = { 0 };
	unsigned int	i = 0;

	setraw();
	while (1)
	{
		while (c != '\n')
		{
			c = 0;
			read(0, &c, sizeof(unsigned int));
			write(1, &c, sizeof(unsigned int));
			line[i++] = c;
		}
		write(1, line, i * sizeof(unsigned int));
		line[0] = 0;
		i = 0;
		c = 0;
	}
	unsetraw();
	return (0);
}
