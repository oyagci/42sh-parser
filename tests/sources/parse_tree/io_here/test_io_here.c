/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_io_here.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:18:59 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 15:31:34 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>
#include <parser/parser.h>
#include <lexer/lexer.h>
#include <check.h>

void		check_io_here_error(enum e_token ttype)
{
	t_token	tarr[] = {
		{ ttype, ft_strdup("dummy") },
		{ T_WORD, ft_strdup("EOF") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 3);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*io = io_here(&p);

	ck_assert(io == NULL);
	ck_assert(p.tlst != NULL);
}

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

START_TEST(test_io_here_syntax)
{
	check_io_here_error(T_LESS);
	check_io_here_error(T_PIPE);
	check_io_here_error(T_WORD);
}
END_TEST

Suite	*test_suite_io_here()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("io_here");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_io_here);
	tcase_add_test(tc, test_io_here_syntax);
	suite_add_tcase(s, tc);
	return (s);
}
