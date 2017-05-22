/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_quote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:15:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 17:30:35 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include <lexer/lexer.h>

void			test_expected_tokens(char *input, t_token *tokens, size_t sz);

START_TEST(lexer_quote_quote)
{
	t_token	tokens[] = {
		{ T_WORD, "'Hello World'" },
		{ T_END, NULL }
	};

	test_expected_tokens("'Hello World'", tokens, sizeof(tokens) / sizeof(t_token));
}
END_TEST

START_TEST(lexer_quote_doublequote)
{
	t_token	tokens[] = {
		{ T_WORD, "\"Hello World\"" },
		{ T_END, NULL }
	};

	test_expected_tokens("\"Hello World\"", tokens, sizeof(tokens) / sizeof(t_token));
}
END_TEST

START_TEST(lexer_quote_backslash)
{
	t_token	tokens[] = {
		{ T_WORD, "Hello\\ World" },
		{ T_END, NULL }
	};

	test_expected_tokens("Hello\\ World", tokens, sizeof(tokens) / sizeof(t_token));
}
END_TEST

START_TEST(lexer_quote_backslash_multiple)
{
	t_token	tokens[] = {
		{ T_WORD, "Hello\\ World\\ Nice" },
		{ T_END, NULL }
	};

	test_expected_tokens("Hello\\ World\\ Nice", tokens, sizeof(tokens) / sizeof(t_token));
}
END_TEST

Suite	*test_suite_lexer_quote(void)
{
	Suite *s;
	TCase *tc_quote;

	s = suite_create("Lexer Quote");
	tc_quote = tcase_create("Core");
	tcase_add_test(tc_quote, lexer_quote_quote);
	tcase_add_test(tc_quote, lexer_quote_doublequote);
	tcase_add_test(tc_quote, lexer_quote_backslash);
	tcase_add_test(tc_quote, lexer_quote_backslash_multiple);
	suite_add_tcase(s, tc_quote);
	return (s);
}
