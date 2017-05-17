/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:13:04 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/17 17:15:23 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <lexer/lexer.h>
#include <check.h>

t_list		*get_tlst(t_token *tarr, size_t sz)
{
	t_list	*lst = NULL;
	t_list	*elem = NULL;
	size_t	i = 0;

	while (i < sz)
	{
		elem = ft_lstnew(NULL, 0);
		elem->content = tarr + i;
		ft_lstpush(&lst, elem);
		i += 1;
	}
	return (lst);
}

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

	ck_assert_str_eq(fname->content.filename->data, "hello");
	ck_assert(((t_token *)p.tlst->content)->type == T_END);
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

	ck_assert_str_eq(fname->content.filename->data, "/Users/oyagci");
}
END_TEST

Suite	*test_suite_filename()
{
	Suite	*s;
	TCase	*tc;

	s = suite_create("filename");
	tc = tcase_create("core");
	tcase_add_test(tc, test_filename);
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
