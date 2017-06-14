/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:20:20 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 12:07:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <check.h>
#include <lexer/lexer.h>

START_TEST(test_lexer_empty_string)
{
	enum e_token expected[] = { T_END };
	t_list	*tlst = lexer("")->tlst;

	ck_assert(((t_token *)tlst->content)->type == expected[0]);
	ck_assert(tlst->next == NULL);
}
END_TEST

START_TEST(test_lexer_single_space)
{
	enum e_token expected[] = { T_END };
	t_list	*tlst = lexer(" ")->tlst;

	ck_assert(((t_token *)tlst->content)->type == expected[0]);
	ck_assert(tlst->next == NULL);
}
END_TEST

START_TEST(test_lexer_multiple_space)
{
	enum e_token expected[] = { T_END };
	t_list	*tlst = lexer("    ")->tlst;

	ck_assert(((t_token *)tlst->content)->type == expected[0]);
	ck_assert(tlst->next == NULL);
}
END_TEST

START_TEST(test_lexer_single_tab)
{
	enum e_token expected[] = { T_END };
	t_list	*tlst = lexer("\t")->tlst;

	ck_assert(((t_token *)tlst->content)->type == expected[0]);
	ck_assert(tlst->next == NULL);
}
END_TEST

START_TEST(test_lexer_multiple_tab)
{
	enum e_token expected[] = { T_END };
	t_list	*tlst = lexer("\t\t\t\t")->tlst;

	ck_assert(((t_token *)tlst->content)->type == expected[0]);
	ck_assert(tlst->next == NULL);
}
END_TEST

START_TEST(test_lexer_spacetab_mix)
{
	enum e_token expected[] = { T_END };
	t_list	*tlst = lexer(" \t    \t   \t   \t")->tlst;

	ck_assert(((t_token *)tlst->content)->type == expected[0]);
	ck_assert(tlst->next == NULL);
}
END_TEST

Suite		*test_suite_lexer()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("empty_input");
	tc = tcase_create("lexer");
	tcase_add_test(tc, test_lexer_empty_string);
	tcase_add_test(tc, test_lexer_single_space);
	tcase_add_test(tc, test_lexer_multiple_space);
	tcase_add_test(tc, test_lexer_single_tab);
	tcase_add_test(tc, test_lexer_multiple_tab);
	tcase_add_test(tc, test_lexer_spacetab_mix);
	suite_add_tcase(s, tc);
	return (s);
}
