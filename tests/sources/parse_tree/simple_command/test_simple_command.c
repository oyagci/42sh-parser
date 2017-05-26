/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:45:11 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/26 17:42:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <parser/parser.h>
#include <lexer/lexer.h>
#include <tests.h>

START_TEST(test_simple_command_input_prefix_only_success)
{
	t_token		tokens[] = { { T_LESS, "<" }, { T_WORD, "input" }, { T_END, NULL } };
	t_parser	*p;
	t_ptree		*ptree;

	p = prepare_parser(tokens, sizeof(tokens) / sizeof(t_token), simple_command);
	ptree = p->ptree;

	ck_assert(ptree != (void *)ERR_SYNTAX);
	ck_assert(ptree != NULL);

	ck_assert(ptree->content->sp_command.prefix != NULL);
	ck_assert(ptree->content->sp_command.prefix->content != NULL);

	t_cmd_prefix *pre = &ptree->content->sp_command.prefix->content->cmd_prefix;

	ck_assert(pre->redirections != NULL);
	ck_assert(pre->redirections->content != NULL);

	t_io_redirect *redirect = &(((t_ptree *)pre->redirections->content)->content->io_redirect);

	ck_assert(redirect->io_file != NULL);
	
	t_io_file *file = &redirect->io_file->content->io_file;

	ck_assert(file->type == IT_LESS);
	ck_assert(file->filename != NULL);

	t_filename *f = &file->filename->content->filename;

	ck_assert_str_eq(f->data, "input");
}
END_TEST

START_TEST(test_simple_command_syntax_error)
{
	t_token		tokens[] = { { T_LESS, "<" }, { T_END, NULL } };
	t_parser	*p;
	t_ptree		*ptree;

	p = prepare_parser(tokens, sizeof(tokens) / sizeof(t_token), simple_command);
	ptree = p->ptree;

	ck_assert(ptree == (void *)ERR_SYNTAX);
}
END_TEST

Suite	*test_suite_simple_command(void)
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("simple_command");
	tc = tcase_create("parse_tree");
	tcase_add_test(tc, test_simple_command_syntax_error);
	tcase_add_test(tc, test_simple_command_input_prefix_only_success);
	suite_add_tcase(s, tc);
	return (s);
}
