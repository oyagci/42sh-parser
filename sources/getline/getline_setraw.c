/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline_setraw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:49:51 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/27 14:53:11 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <termcap.h>

extern struct termios	g_tattr_save;

void					getline_setraw(void)
{
	struct termios	tattr;

	tcgetattr(STDIN_FILENO, &tattr);
	tcgetattr(STDIN_FILENO, &g_tattr_save);
	tattr.c_cc[VTIME] = 0;
	tattr.c_cc[VMIN] = 1;
	tattr.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
