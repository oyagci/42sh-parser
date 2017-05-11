/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:02:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/27 16:30:04 by oyagci           ###   ########.fr       */
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
	int						(*f)(const unsigned char *const);
};

int							key_is_backspace(const unsigned char *const buffer);
int							key_is_page_down(const unsigned char *const buffer);
int							key_is_page_up(const unsigned char *const buffer);
int							key_is_delete(const unsigned char *const buffer);
int							key_is_ctrl_a(const unsigned char *const buffer);
int							key_is_ctrl_b(const unsigned char *const buffer);
int							key_is_ctrl_d(const unsigned char *const buffer);
int							key_is_ctrl_e(const unsigned char *const buffer);
int							key_is_ctrl_f(const unsigned char *const buffer);
int							key_is_ctrl_w(const unsigned char *const buffer);
int							key_is_alt_w(const unsigned char *const buffer);
int							key_is_alt_v(const unsigned char *const buffer);
int							key_is_alt_c(const unsigned char *const buffer);
int							key_is_enter(const unsigned char *const buffer);
int							key_is_right(const unsigned char *const buffer);
int							key_is_left(const unsigned char *const buffer);
int							key_is_down(const unsigned char *const buffer);
int							key_is_home(const unsigned char *const buffer);
int							key_is_end(const unsigned char *const buffer);
int							key_is_tab(const unsigned char *const buffer);
int							key_is_up(const unsigned char *const buffer);

#endif
