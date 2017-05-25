/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:35:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 13:06:57 by oyagci           ###   ########.fr       */
/* ************************************************************************** */

#include <check.h>
#include <tests.h>
#include <parser/parser.h>
#include <lexer/lexer.h>

void		check_io_redirect_error(enum e_token ttype)
{
	t_token	tarr[] = {
		{ ttype, ft_strdup("dummy") },
		{ T_WORD, ft_strdup("file.txt") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 3);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*io = io_redirect(&p);

	ck_assert(io == NULL);
	ck_assert(p.tlst != NULL);
}

START_TEST(test_io_redirect_missing)
{
	t_token	tarr[] = {
		{ T_GREAT, ">" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 2);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*io;
	io = io_redirect(&p);

	ck_assert(io == (void *)ERR_SYNTAX);
}
END_TEST

START_TEST(test_io_redirect_syntax_error)
{
	check_io_redirect_error(T_PIPE);
}
END_TEST

START_TEST(test_io_redirect)
{
	t_token	tarr[] = {
		{ T_IO_NUMBER, "2" },
		{ T_GREAT, ">" },
		{ T_WORD, "/dev/null" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 4);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*io;
	io = io_redirect(&p);

	ck_assert(io != NULL);
	ck_assert(p.tlst != NULL);

	ck_assert(io->content->io_redirect.io_number == 2);
	ck_assert(((t_token *)p.tlst->content)->type == T_END);

	ck_assert(io->content->io_redirect.io_file != NULL);

	t_io_redirect	*io_redirect = &io->content->io_redirect;
	t_io_file		*io_file = &io_redirect->io_file->content->io_file;
	t_filename		*filename = &io_file->filename->content->filename;

	ck_assert_str_eq(filename->data, "/dev/null");
}
END_TEST

START_TEST(test_io_redirect_default)
{
	t_token	tarr[] = {
		{ T_GREAT, ">" },
		{ T_WORD, "/dev/null" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 3);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*io;
	io = io_redirect(&p);

	ck_assert(io != NULL);
	ck_assert(p.tlst != NULL);

	ck_assert(((t_token *)p.tlst->content)->type == T_END);

	ck_assert(io->content->io_redirect.io_file != NULL);

	t_io_redirect	*io_redirect = &io->content->io_redirect;
	t_io_file		*io_file = &io_redirect->io_file->content->io_file;
	t_filename		*filename = &io_file->filename->content->filename;

	ck_assert_str_eq(filename->data, "/dev/null");
}
END_TEST

START_TEST(test_io_redirect_syntax)
{
	t_token	tarr[] = {
		{ T_GREAT, ">" },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 2);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*io;
	io = io_redirect(&p);

	ck_assert(io == (void *)ERR_SYNTAX);
}
END_TEST

Suite	*test_suite_io_redirect()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("io_redirect");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_io_redirect);
	tcase_add_test(tc, test_io_redirect_default);
	tcase_add_test(tc, test_io_redirect_syntax_error);
	tcase_add_test(tc, test_io_redirect_syntax);
	tcase_add_test(tc, test_io_redirect_missing);
	suite_add_tcase(s, tc);
	return (s);
}
