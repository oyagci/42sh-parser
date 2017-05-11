/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline_unsetraw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 14:50:28 by oyagci            #+#    #+#             */
/*   Updated: 2017/03/27 14:53:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <termcap.h>
#include <unistd.h>

extern struct termios	g_tattr_save;

void					getline_unsetraw(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_tattr_save);
}
