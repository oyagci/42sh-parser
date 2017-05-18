/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:33:28 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/18 17:12:34 by oyagci           ###   ########.fr       */
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
	srunner_run_all(sr, CK_VERBOSE);
	srunner_free(sr);
	return (0);
}

int			main(void)
{
	Suite *(*tests[])() = {
		test_suite_filename,
		test_suite_here_end,
		test_suite_io_here,
	};

	for (int i = 0; i < 3; i++)
		do_test(tests[i]);
	return (0);
}
