/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_io_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 10:06:24 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 15:27:59 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>
#include <parser/parser.h>
#include <lexer/lexer.h>
#include <check.h>

void		check_filename(t_ptree *f, char *expected)
{
	ck_assert(f->type == NT_FILENAME);
	ck_assert(f->content->filename.data != NULL);
	ck_assert_str_eq(f->content->filename.data, expected);
}

void		check_io_file(t_ptree *io, enum e_io_type type, char *expected)
{
	ck_assert(io != NULL);
	ck_assert(io->type == NT_IO_FILE);
	ck_assert(io->content != NULL);
	ck_assert(io->content->io_file.type == type);
	check_filename(io->content->io_file.filename, expected);
}

void		check_io_file_type(enum e_io_type iotype, enum e_token ttype)
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

	t_ptree	*io = io_file(&p);

	ck_assert(io != NULL);
	ck_assert(p.tlst != NULL);

	check_io_file(io, iotype, "file.txt");

	ck_assert(p.tlst != NULL);
	ck_assert(((t_token *)p.tlst->content)->type == T_END);
}

void		check_io_file_error(enum e_token ttype)
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

	t_ptree	*io = io_file(&p);

	ck_assert(io == NULL);
	ck_assert(p.tlst != NULL);
}

START_TEST(test_io_file)
{
	check_io_file_type(IT_LESS, T_LESS);
	check_io_file_type(IT_LESSAND, T_LESSAND);
	check_io_file_type(IT_GREAT, T_GREAT);
	check_io_file_type(IT_GREATAND, T_GREATAND);
	check_io_file_type(IT_DGREAT, T_DGREAT);
}
END_TEST

START_TEST(test_io_file_syntax_error)
{
	check_io_file_error(T_PIPE);
	check_io_file_error(T_DLESS);
	check_io_file_error(T_OR);
	check_io_file_error(T_AND);
	check_io_file_error(T_SEMICOL);
}
END_TEST

Suite	*test_suite_io_file()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("io_file");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_io_file);
	tcase_add_test(tc, test_io_file_syntax_error);
	suite_add_tcase(s, tc);
	return (s);
}
