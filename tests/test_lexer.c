/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:47:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 10:38:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer/lexer.h>
#include <stdlib.h>
#include <check.h>

START_TEST(lexer_empty_string)
{
	t_lexer	*l;
	t_list	*tlst;
	t_token	*t;

	l = lexer("");
	tlst = l->tlst;
	ck_assert(tlst != NULL);
	ck_assert(tlst->content != NULL);
	ck_assert(tlst->next == NULL);

	t = tlst->content;
	ck_assert(t->type == T_END);
}
END_TEST

Suite	*test_suite_lexer()
{
	Suite *s;
	TCase *tc_core;

	s = suite_create("Lexer");
	tc_core = tcase_create("Core");
	tcase_add_test(tc_core, lexer_empty_string);
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
