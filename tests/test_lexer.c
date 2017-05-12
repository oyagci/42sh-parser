/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:47:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 16:32:41 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>
#include <check.h>

void			test_expected_tokens(char *input, t_token *tokens, size_t sz)
{
	t_lexer	*l;
	size_t	i;

	l = lexer(input);
	i = 0;
	while (i < sz)
	{
		if (tokens[i].data)
			ck_assert_str_eq(tokens[i].data, ((t_token *)l->tlst->content)->data);
		else
			ck_assert(((t_token *)l->tlst->content)->data == NULL);
		ft_putnbr(((t_token *)l->tlst->content)->type);
		ft_putchar('\n');
		ck_assert(tokens[i].type == ((t_token *)l->tlst->content)->type);
		l->tlst = l->tlst->next;
		i += 1;
	}
	lexer_delete(&l);
}

START_TEST(lexer_empty_string)
{
	t_token	tokens[] = { { T_END, NULL } };

	test_expected_tokens("", tokens, sizeof(tokens) / sizeof(t_token));
}
END_TEST

START_TEST(lexer_single_argument)
{
	t_token tokens[] = {
		{ T_WORD, "ls" },
		{ T_END, NULL } };

	test_expected_tokens("ls", tokens, sizeof(tokens) / sizeof(t_token));
}
END_TEST

START_TEST(lexer_two_argument)
{
	t_token tokens[] = {
		{ T_WORD, "ls" },
		{ T_WORD, "-la" },
		{ T_END, NULL }
	};

	test_expected_tokens("ls -la", tokens, sizeof(tokens) / sizeof(t_token));
}
END_TEST

Suite	*test_suite_lexer()
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Lexer");
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, lexer_empty_string);
	tcase_add_test(tc_core, lexer_single_argument);
	tcase_add_test(tc_core, lexer_two_argument);
	suite_add_tcase(s, tc_core);
	return (s);
}

int		main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = test_suite_lexer();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return ((number_failed == 0) ? EXIT_SUCCESS: EXIT_FAILURE);
}
