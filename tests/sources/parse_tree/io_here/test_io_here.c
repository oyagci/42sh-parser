/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_io_here.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:18:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 17:34:43 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>
#include <parser/parser.h>
#include <lexer/lexer.h>
#include <check.h>

START_TEST(test_io_here)
{
	t_token	tarr[] = {
		{ T_DLESS, ft_strdup("<<") },
		{ T_WORD, ft_strdup("EOF") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 3);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*fname = io_here(&p);

	ck_assert(fname != NULL);
	ck_assert(p.tlst != NULL);
	ck_assert(fname->content->io_here.here_end != NULL);
	ck_assert(p.tlst != NULL);
	ck_assert(((t_token *)p.tlst->content)->type == T_END);
}
END_TEST

Suite	*test_suite_io_here()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("io_here");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_io_here);
	suite_add_tcase(s, tc);
	return (s);
}
