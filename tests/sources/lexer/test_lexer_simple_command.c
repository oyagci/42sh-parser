/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer_simple_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 12:08:14 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/24 12:20:06 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <check.h>
#include <lexer/lexer.h>

START_TEST(test_lexer_single_argument)
{
	enum e_token	expected[] = { T_WORD };
	size_t			sz = sizeof(expected) / sizeof(enum e_token);
	size_t			i = 0;
	t_list	*tlst = lexer("ls")->tlst;

	i = 0;
	while (i < sz)
	{
		ck_assert(tlst != NULL);
		ck_assert(((t_token *)tlst->content)->type == expected[i]);
		tlst = tlst->next;
		i += 1;
	}
	ck_assert(tlst != NULL);
	ck_assert(((t_token *)tlst->content)->type == T_END);
	ck_assert(tlst->next == NULL);
}
END_TEST

START_TEST(test_lexer_two_argument)
{
	enum e_token	expected[] = { T_WORD, T_WORD };
	size_t			sz = sizeof(expected) / sizeof(enum e_token);
	size_t			i = 0;
	t_list	*tlst = lexer("ls -la")->tlst;

	i = 0;
	while (i < sz)
	{
		ck_assert(tlst != NULL);
		ck_assert(((t_token *)tlst->content)->type == expected[i]);
		tlst = tlst->next;
		i += 1;
	}
	ck_assert(tlst != NULL);
	ck_assert(((t_token *)tlst->content)->type == T_END);
	ck_assert(tlst->next == NULL);
}
END_TEST

START_TEST(test_lexer_spaced_arguments)
{
	enum e_token	expected[] = { T_WORD, T_WORD };
	size_t			sz = sizeof(expected) / sizeof(enum e_token);
	size_t			i = 0;
	t_list	*tlst = lexer("   ls    -la   ")->tlst;

	i = 0;
	while (i < sz)
	{
		ck_assert(tlst != NULL);
		ck_assert(((t_token *)tlst->content)->type == expected[i]);
		tlst = tlst->next;
		i += 1;
	}
	ck_assert(tlst != NULL);
	ck_assert(((t_token *)tlst->content)->type == T_END);
	ck_assert(tlst->next == NULL);
}
END_TEST

Suite		*test_suite_lexer_simple_command()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("simple_input");
	tc = tcase_create("lexer");
	tcase_add_test(tc, test_lexer_single_argument);
	tcase_add_test(tc, test_lexer_two_argument);
	tcase_add_test(tc, test_lexer_spaced_arguments);
	suite_add_tcase(s, tc);
	return (s);
}
