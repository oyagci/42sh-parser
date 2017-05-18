/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:13:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 14:48:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>
#include <parser/parser.h>
#include <lexer/lexer.h>
#include <check.h>

START_TEST(test_filename)
{
	t_token	tarr[] = {
		{ T_WORD, ft_strdup("hello") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 2);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*fname = filename(&p);
	ck_assert(fname != NULL);

	ck_assert_str_eq(fname->content->filename.data, "hello");
	ck_assert(((t_token *)p.tlst->content)->type == T_END);
}
END_TEST

START_TEST(test_filename_two)
{
	t_token	tarr[] = {
		{ T_WORD, ft_strdup("hello") },
		{ T_WORD, ft_strdup("World") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 3);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*fname = filename(&p);
	ck_assert(fname != NULL);

	ck_assert_str_eq(fname->content->filename.data, "hello");
	ck_assert(((t_token *)p.tlst->content)->type == T_WORD);
}
END_TEST

START_TEST(test_filename_tilde_expansion)
{
	t_token	tarr[] = {
		{ T_WORD, ft_strdup("~") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 2);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*fname = filename(&p);
	ck_assert(fname != NULL);

	ck_assert_str_eq(fname->content->filename.data, "/Users/oyagci");
}
END_TEST

START_TEST(test_filename_syntax_error)
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

	t_ptree	*fname = filename(&p);
	ck_assert(fname == NULL);
	ck_assert(((t_token *)p.tlst->content)->type == T_LESS);
}
END_TEST

Suite	*test_suite_filename()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("filename");
	tc = tcase_create("core");
	tcase_add_test(tc, test_filename);
	tcase_add_test(tc, test_filename_two);
	tcase_add_test(tc, test_filename_syntax_error);
	tcase_add_test(tc, test_filename_tilde_expansion);
	suite_add_tcase(s, tc);
	return (s);
}

int		main(void)
{
	Suite	*fname;
	SRunner	*sr;

	fname = test_suite_filename();
	sr = srunner_create(fname);
	srunner_run_all(sr, CK_VERBOSE);
	srunner_free(sr);
	return (0);
}
