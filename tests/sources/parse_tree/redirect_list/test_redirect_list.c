/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_redirect_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:33:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 13:23:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>
#include <parser/parser.h>
#include <lexer/lexer.h>
#include <check.h>

START_TEST(test_redirect_list)
{
	t_token	tarr[] = {
		{ T_LESS, ft_strdup("<") },
		{ T_WORD, ft_strdup("input.txt") },
		{ T_GREAT, ft_strdup(">") },
		{ T_WORD, ft_strdup("output.txt") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 5);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*redirect = redirect_list(&p);
	size_t	i = 0;

	ck_assert(redirect != NULL);
	ck_assert(redirect->type == NT_REDIRECT_LIST);

	t_list	*list = redirect->content->redirect_list.list;

	while (list)
	{
		t_ptree *node = list->content;

		ck_assert(node != NULL);
		ck_assert(node->type == NT_IO_REDIRECT);
		ck_assert(node->content != NULL);

		list = list->next;
		i += 1;
	}
	ck_assert(i == 2);
	ck_assert(((t_token *)p.tlst->content)->type == T_END);
}
END_TEST

START_TEST(test_redirect_list_syntax)
{
	t_token	tarr[] = {
		{ T_PIPE, ft_strdup("|") },
		{ T_WORD, ft_strdup("input.txt") },
		{ T_GREAT, ft_strdup(">") },
		{ T_WORD, ft_strdup("output.txt") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 5);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*redirect = redirect_list(&p);

	ck_assert(redirect == NULL);
	ck_assert(((t_token *)p.tlst->content)->type == T_PIPE);
}
END_TEST

START_TEST(test_redirect_list_syntax_incomplete)
{

	t_token	tarr[] = {
		{ T_LESS, ft_strdup("<") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 2);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*redirect = redirect_list(&p);
	ck_assert(redirect == (void *)ERR_SYNTAX);
}
END_TEST

Suite	*test_suite_redirect_list()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("redirect_list");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_redirect_list);
	tcase_add_test(tc, test_redirect_list_syntax);
	tcase_add_test(tc, test_redirect_list_syntax_incomplete);
	suite_add_tcase(s, tc);
	return (s);
}
