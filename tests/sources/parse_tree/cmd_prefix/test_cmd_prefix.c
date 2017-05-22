/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 13:27:24 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 14:16:43 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <tests.h>
#include <lexer/lexer.h>
#include <parser/parser.h>

START_TEST(test_cmd_prefix)
{
	t_token	tarr[] = {
		{ T_LESS, "<" },
		{ T_WORD, "Hello" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 3);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*node;
	node = cmd_prefix(&p);
	ck_assert(node != NULL);
	ck_assert(node->type == NT_CMD_PREFIX);
	ck_assert(node->content->cmd_prefix.redirections != NULL);
}
END_TEST

START_TEST(test_cmd_prefix_syntax_error)
{
	t_token	tarr[] = {
		{ T_LESS, "<" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 2);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*node;
	node = cmd_prefix(&p);
	ck_assert(node == (void *)ERR_SYNTAX);
}
END_TEST

Suite	*test_suite_cmd_prefix()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("cmd_prefix");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_cmd_prefix_syntax_error);
	tcase_add_test(tc, test_cmd_prefix);
	suite_add_tcase(s, tc);
	return (s);
}
