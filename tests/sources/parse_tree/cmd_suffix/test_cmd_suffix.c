/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd_suffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:09:28 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 15:40:38 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <tests.h>
#include <lexer/lexer.h>
#include <parser/parser.h>

START_TEST(test_cmd_suffix)
{
	t_token	tarr[] = {
		{ T_LESS, "<" },
		{ T_WORD, "input" },
		{ T_GREAT, ">" },
		{ T_WORD, "output" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 5);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*suffix;
	suffix = cmd_suffix(&p);
	ck_assert(cmd_suffix != NULL);
}
END_TEST

START_TEST(test_cmd_suffix_syntax)
{
	t_token	tarr[] = {
		{ T_PIPE, "|" },
		{ T_WORD, "input" },
		{ T_GREAT, ">" },
		{ T_WORD, "output" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 5);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*suffix;

	suffix = cmd_suffix(&p);

	ck_assert(suffix == NULL);
}
END_TEST

Suite	*test_suite_cmd_suffix()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("cmd_suffix");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_cmd_suffix);
	tcase_add_test(tc, test_cmd_suffix_syntax);
	suite_add_tcase(s, tc);
	return (s);
}
