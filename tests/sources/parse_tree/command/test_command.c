/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:31:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 16:53:28 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <parser/parser.h>
#include <tests.h>

START_TEST(test_command_syntax_pipe_error)
{
	t_token		tokens[] = { { T_PIPE, "|" }, { T_END, NULL } };
	t_parser	*p;
	t_ptree		*ptree;
	t_list		*head;

	p = prepare_parser(tokens, sizeof(tokens) / sizeof(t_token));
	ptree = p->ptree;
	head = p->tlst;

	ck_assert(ptree == (void *)ERR_SYNTAX);
	ck_assert(p->tlst == head);

	ptree_free(&p->ptree);
}
END_TEST

Suite	*test_suite_command(void)
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("command");
	tc = tcase_create("parse_tree");

	tcase_add_test(tc, test_command_syntax_pipe_error);

	suite_add_tcase(s, tc);
	return (s);
}
