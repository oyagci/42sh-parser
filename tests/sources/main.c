/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:33:28 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/19 12:52:08 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>
#include <check.h>

int			do_test(Suite *(*current)())
{
	Suite	*suite;
	SRunner	*sr;

	suite = current();
	sr = srunner_create(suite);
	srunner_run_all(sr, CK_NORMAL);
	srunner_free(sr);
	return (0);
}

int			main(void)
{
	Suite *(*tests[])() = {
		test_suite_filename,
		test_suite_here_end,
		test_suite_io_here,
		test_suite_io_file,
		test_suite_redirect_list
	};
	size_t	nb = 5;

	for (size_t i = 0; i < nb; i++)
		do_test(tests[i]);
	return (0);
}
