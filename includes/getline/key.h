/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:02:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/06/05 11:15:38 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

typedef	enum e_keycode		t_keycode;
enum	e_keycode
{
	KEYCODE_UP = 1,
	KEYCODE_TAB,
	KEYCODE_END,
	KEYCODE_HOME,
	KEYCODE_DOWN,
	KEYCODE_LEFT,
	KEYCODE_RIGHT,
	KEYCODE_ENTER,
	KEYCODE_ALT_W,
	KEYCODE_ALT_C,
	KEYCODE_ALT_V,
	KEYCODE_CTRL_A,
	KEYCODE_CTRL_B,
	KEYCODE_CTRL_C,
	KEYCODE_CTRL_D,
	KEYCODE_CTRL_E,
	KEYCODE_CTRL_F,
	KEYCODE_CTRL_W,
	KEYCODE_DELETE,
	KEYCODE_PAGE_UP,
	KEYCODE_PAGE_DOWN,
	KEYCODE_BACKSPACE,
	KEYCODE_NONE
};

typedef	struct s_key		t_key;
struct						s_key
{
	t_keycode				keycode;
};

typedef	struct s_key_funcs	t_key_funcs;
struct						s_key_funcs
{
	t_keycode				keycode;
	int						(*f)(unsigned int);
};

int							key_is_backspace(unsigned int buffer);
int							key_is_page_down(unsigned int buffer);
int							key_is_page_up(unsigned int buffer);
int							key_is_delete(unsigned int buffer);
int							key_is_ctrl_a(unsigned int buffer);
int							key_is_ctrl_b(unsigned int buffer);
int							key_is_ctrl_d(unsigned int buffer);
int							key_is_ctrl_e(unsigned int buffer);
int							key_is_ctrl_f(unsigned int buffer);
int							key_is_ctrl_w(unsigned int buffer);
int							key_is_alt_w(unsigned int buffer);
int							key_is_alt_v(unsigned int buffer);
int							key_is_alt_c(unsigned int buffer);
int							key_is_enter(unsigned int buffer);
int							key_is_right(unsigned int buffer);
int							key_is_left(unsigned int buffer);
int							key_is_down(unsigned int buffer);
int							key_is_home(unsigned int buffer);
int							key_is_end(unsigned int buffer);
int							key_is_tab(unsigned int buffer);
int							key_is_up(unsigned int buffer);

#endif
