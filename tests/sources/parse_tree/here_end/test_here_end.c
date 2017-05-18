/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_here_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:13:18 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 15:22:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>
#include <parser/parser.h>
#include <lexer/lexer.h>
#include <check.h>

START_TEST(test_here_end)
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

	t_ptree	*hend = here_end(&p);
	ck_assert(hend != NULL);

	ck_assert_str_eq(hend->content->here_end.data, "hello");
	ck_assert(((t_token *)p.tlst->content)->type == T_END);
}
END_TEST

START_TEST(test_here_end_syntax_error)
{
	t_token	tarr[] = {
		{ T_PIPE, ft_strdup("|") },
		{ T_END, NULL },
	};
	t_list	*lst = get_tlst(tarr, 2);
	t_parser p = {
		lst,
		NULL,
	};

	t_ptree	*hend = here_end(&p);
	ck_assert(hend == NULL);
	ck_assert(((t_token *)p.tlst->content)->type == T_PIPE);
}
END_TEST

Suite	*test_suite_here_end()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("here_end");
	tc = tcase_create("core");
	tcase_add_test(tc, test_here_end);
	suite_add_tcase(s, tc);
	return (s);
}

int		main(void)
{
	Suite *hend;
	SRunner *sr;

	hend = test_suite_here_end();
	sr = srunner_create(hend);
	srunner_run_all(sr, CK_VERBOSE);
	srunner_free(sr);
}
