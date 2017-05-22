/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptree_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:58:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/05/22 16:23:21 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>
#include <stdlib.h>

void			ptree_free(t_ptree **tree)
{
	if ((*tree))
	{
		if ((*tree)->type == NT_SIMPLE_COMMAND && 0)
			simple_command_free(&(*tree)->content->sp_command);
		if ((*tree)->type == NT_CMD_NAME && 0)
			cmd_name_free(&(*tree)->content->cmd_name);
		if ((*tree)->type == NT_CMD_WORD && 0)
			cmd_word_free(&(*tree)->content->cmd_word);
		if ((*tree)->type == NT_IO_HERE && 0)
			io_here_free(&(*tree)->content->io_here);
		if ((*tree)->type == NT_HERE_END && 0)
			here_end_free(&(*tree)->content->here_end);
		if ((*tree)->type == NT_FILENAME && 0)
			filename_free(&(*tree)->content->filename);
		if ((*tree)->type == NT_IO_FILE)
			io_file_free(&(*tree)->content->io_file);
		if ((*tree)->type == NT_REDIRECT_LIST)
			redirect_list_free(&(*tree)->content->redirect_list);
		if ((*tree)->type == NT_HERE_END)
			here_end_free(&(*tree)->content->here_end);
		if ((*tree)->type == NT_CMD_PREFIX)
			cmd_prefix_free(&(*tree)->content->cmd_prefix);
		free((*tree)->content);
		free(*tree);
		*tree = NULL;
	}
}
