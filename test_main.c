/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 17:10:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/12 17:14:42 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>

/*
** TESTS PROTOTYPES
*/

Suite	*test_suite_lexer_simple();

int		main(void)
{
	int number_failed;
	Suite *lexer_simple;
	SRunner *sr;

	lexer_simple = test_suite_lexer_simple();
	sr = srunner_create(lexer_simple);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return ((number_failed == 0) ? 0: 1);
}
