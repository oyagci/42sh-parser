/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 13:56:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 12:21:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <linehistory/linehistory.h>
#include <getline/getline.h>
#include <getline/key.h>
#include <libft.h>

static t_keycode	get_key(unsigned int c)
{
	const t_key_funcs	funcs[] = { { KEYCODE_UP, key_is_up },
		{ KEYCODE_END, key_is_end }, { KEYCODE_HOME, key_is_home },
		{ KEYCODE_DOWN, key_is_down }, { KEYCODE_LEFT, key_is_left },
		{ KEYCODE_RIGHT, key_is_right }, { KEYCODE_ENTER, key_is_enter },
		{ KEYCODE_ALT_W, key_is_alt_w }, { KEYCODE_ALT_C, key_is_alt_c },
		{ KEYCODE_ALT_V, key_is_alt_v }, { KEYCODE_CTRL_W, key_is_ctrl_w },
		{ KEYCODE_CTRL_B, key_is_ctrl_b }, { KEYCODE_CTRL_F, key_is_ctrl_f },
		{ KEYCODE_PAGE_UP, key_is_page_up },
		{ KEYCODE_PAGE_DOWN, key_is_page_down },
		{ KEYCODE_CTRL_D, key_is_ctrl_d }, { KEYCODE_TAB, key_is_tab },
		{ KEYCODE_CTRL_A, key_is_ctrl_a }, { KEYCODE_CTRL_E, key_is_ctrl_e },
		{ KEYCODE_BACKSPACE, key_is_backspace }, { KEYCODE_NONE, NULL } };
	size_t				i;

	i = 0;
	while (funcs[i].keycode != KEYCODE_NONE)
	{
		if (funcs[i].f(c))
			return (funcs[i].keycode);
		i += 1;
	}
	return (KEYCODE_NONE);
}

static int			process_key_regular(t_keycode keycode, t_line *l)
{
	const t_keycode	k[] = { KEYCODE_CTRL_W, KEYCODE_PAGE_UP, KEYCODE_PAGE_DOWN,
		KEYCODE_CTRL_B, KEYCODE_CTRL_F, KEYCODE_CTRL_A, KEYCODE_CTRL_E,
		KEYCODE_ALT_C, KEYCODE_ALT_V, KEYCODE_UP, KEYCODE_DOWN, KEYCODE_TAB };
	void			(*const f[])(t_line *) = { line_del_word, line_up,
		line_down, line_prev_word, line_next_word, line_goto_begin,
		line_goto_end, line_copy, line_paste, linehist_load_prev,
		linehist_load_next, line_autocomplete };
	size_t			i;
	int				ret;

	i = 0;
	while (i < sizeof(k) / sizeof(t_keycode))
	{
		if ((ret = (keycode == k[i])))
		{
			f[i](l);
			return (ret);
		}
		i += 1;
	}
	return (0);
}

int					process_key(unsigned int buffer, t_line *l)
{
	t_keycode keycode;

	keycode = get_key(buffer);
	if (!process_key_regular(keycode, l))
	{
		if (keycode == KEYCODE_LEFT && l->index > 0)
			l->index -= 1;
		else if (keycode == KEYCODE_RIGHT && l->index < l->len)
			l->index += 1;
		else if (keycode == KEYCODE_BACKSPACE && l->index > 0)
			line_delchar(l);
		else if (keycode == KEYCODE_ENTER)
		{
			linehist_reset_index();
			return (0);
		}
		else if (keycode == KEYCODE_CTRL_D && l->len == 0)
			return (-2);
		else if (keycode == KEYCODE_NONE)
			line_addchar(buffer, l);
	}
	return (1);
}
