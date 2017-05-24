/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:20:20 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 10:28:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <check.h>
#include <lexer/lexer.h>

START_TEST(test_lexer)
{
	// enum e_token	token[] = { T_IO_NUMBER, T_GREAT, T_WORD, };

	t_list	*t = lex("2>hello_world");
	ck_assert(((t_token *)t->content)->type == T_IO_NUMBER);
}
END_TEST

Suite		*test_suite_lexer()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("test");
	tc = tcase_create("lexer");
	tcase_add_test(tc, test_lexer);
	suite_add_tcase(s, tc);
	return (s);
}
