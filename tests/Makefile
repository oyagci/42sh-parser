# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 10:30:00 by oyagci            #+#    #+#              #
#    Updated: 2017/05/26 16:56:23 by oyagci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRPATH				= /Users/oyagci/Projects/42/42sh/

NAME				= tests.out
CC					= clang
CFLAGS				= -Wall -Wextra -Werror

_BASEFOLDER		= ../
_SOURCES		= sources/
_INCLUDES		= includes/

_FILES_			= environ/environ_setvalue.c \
				  environ/environ_getvalue.c \
				  environ/environ_get_str.c \
				  environ/environ_add_var.c \
				  environ/environ_remove.c \
				  environ/environ_getvar.c \
				  environ/environ_print.c \
				  environ/environ_load.c \
				  environ/environ_get.c \
				  environ/environ_dup.c

_FILES_			+= getline/key/key_is_backspace.c \
				   getline/key/key_is_page_down.c \
				   getline/key/key_is_page_up.c \
				   getline/key/key_is_delete.c \
				   getline/key/key_is_ctrl_a.c \
				   getline/key/key_is_ctrl_b.c \
				   getline/key/key_is_ctrl_d.c \
				   getline/key/key_is_ctrl_e.c \
				   getline/key/key_is_ctrl_f.c \
				   getline/key/key_is_ctrl_w.c \
				   getline/key/key_is_alt_c.c \
				   getline/key/key_is_alt_v.c \
				   getline/key/key_is_alt_w.c \
				   getline/key/key_is_right.c \
				   getline/key/key_is_enter.c \
				   getline/key/key_is_left.c \
				   getline/key/key_is_down.c \
				   getline/key/key_is_home.c \
				   getline/key/key_is_end.c \
				   getline/key/key_is_tab.c \
				   getline/key/key_is_up.c

_FILES_			+= getline/getline_unsetraw.c \
				   getline/getline_setraw.c

_FILES_			+= getline/print_prompt.c \
				   getline/process_key.c \
				   getline/ft_getline.c \
				   getline/ft_putc.c

_FILES_			+= getline/line/line_grow_if_needed.c \
				   getline/line/line_autocomplete.c \
				   getline/line/line_goto_begin.c \
				   getline/line/line_next_word.c \
				   getline/line/line_prev_word.c \
				   getline/line/line_del_word.c \
				   getline/line/line_goto_end.c \
				   getline/line/line_addchar.c \
				   getline/line/line_delchar.c \
				   getline/line/line_print.c \
				   getline/line/line_paste.c \
				   getline/line/line_size.c \
				   getline/line/line_init.c \
				   getline/line/line_down.c \
				   getline/line/line_copy.c \
				   getline/line/ln_putc.c \
				   getline/line/line_up.c

_FILES_			+= getline/line/autocomplete/get_current_word.c \
				   getline/line/autocomplete/find_command.c

_FILES_			+= shell/builtins/builtin_env_print_env.c \
				   shell/builtins/builtin_unsetenv.c \
				   shell/builtins/builtin_env_cmd.c \
				   shell/builtins/builtin_setenv.c \
				   shell/builtins/builtin_echo.c \
				   shell/builtins/builtin_exit.c \
				   shell/builtins/builtin_env.c \
				   shell/builtins/builtin_cd.c

_FILES_			+= shell/signals/signal_check.c

_FILES_			+= shell/arg_count.c \
				   shell/dup3.c

_FILES_			+= linehistory/linehist_get_prevline.c \
				   linehistory/linehist_get_nextline.c \
				   linehistory/linehist_reset_index.c \
				   linehistory/linehist_copy_line.c \
				   linehistory/linehist_load_prev.c \
				   linehistory/linehist_load_next.c \
				   linehistory/linehist_add.c

_FILES_			+= lexer/lexer.c \
				   lexer/lexer_init.c \
				   lexer/lexer_init_tlst.c \
				   lexer/lexer_init_slst.c \
				   lexer/lexer_delete.c \
				   lexer/lexer_get_next_token.c \
				   lexer/lexer_delimite_current_token.c \
				   lexer/lexer_del_token.c \
				   lexer/lexer_del_symbol.c \
				   lexer/lexer_symbol_top.c \
				   lexer/lexer_symbol_push.c \
				   lexer/lexer_current_add_char.c \
				   lexer/lexer_symbol_pop.c \
				   lexer/lexer_token_new.c \
				   lexer/lexer_check_top.c \
				   lexer/lexer_check_quote.c \
				   lexer/lexer_check_delimite.c \
				   lexer/is_last_op_char.c \
				   lexer/is_opstart.c \

_FILES_			+= parser/ptree_init.c \
				   parser/cmd_name.c \
				   parser/cmd_prefix.c \
				   parser/cmd_suffix.c \
				   parser/filename.c \
				   parser/io_file.c \
				   parser/io_redirect.c \
				   parser/io_here.c \
				   parser/here_end.c \
				   parser/parser_expect.c \
				   parser/parser_peek.c \
				   parser/ptree_free.c \
				   parser/ptree_new.c \
				   parser/cmd_word.c \
				   parser/simple_command.c \
				   parser/print/ptree_print.c \
				   parser/simple_command_free.c \
				   parser/io_here_free.c \
				   parser/here_end_free.c \
				   parser/redirect_list_free.c \
				   parser/io_redirect_free.c \
				   parser/io_file_free.c \
				   parser/filename_free.c \
				   parser/cmd_name_free.c \
				   parser/cmd_word_free.c \
				   parser/cmd_prefix_free.c \
				   parser/cmd_suffix_free.c \
				   parser/linebreak.c \
				   parser/newline_list.c \
				   parser/command.c \
				   parser/pipe_sequence.c \
				   parser/compound_command.c \
				   parser/redirect_list.c \
				   parser/subshell.c \
				   parser/separator.c \
				   parser/compound_list.c \
				   parser/separator_op.c \
				   parser/term.c \
				   parser/and_or.c \
				   parser/pipeline.c \
				   parser/list.c \
				   parser/and_or_free.c \
				   parser/complete_command_free.c \
				   parser/list_free.c \
				   parser/pipeline_free.c \
				   parser/pipe_sequence_free.c \
				   parser/command_free.c \
				   parser/subshell_free.c \
				   parser/compound_list_free.c \
				   parser/compound_command_free.c \
				   parser/term_free.c

_TEST_FILES_	= get_tlst.c main.c prepare_parser.c

_TEST_FILES_	+= parse_tree/here_end/test_here_end.c \
				   parse_tree/filename/test_filename.c \
				   parse_tree/io_here/test_io_here.c \
				   parse_tree/io_file/test_io_file.c \
				   parse_tree/redirect_list/test_redirect_list.c \
				   parse_tree/cmd_suffix/test_cmd_suffix.c \
				   parse_tree/io_redirect/test_io_redirect.c \
				   parse_tree/cmd_prefix/test_cmd_prefix.c \
				   parse_tree/command/test_command.c \
				   parse_tree/simple_command/test_simple_command.c

_TEST_FILES_	+= lexer/test_lexer.c \
				   lexer/test_lexer_simple_command.c

TEST_FILES		= $(addprefix sources/,$(_TEST_FILES_))

SRCFOLDER		= $(addprefix $(_BASEFOLDER),$(_SOURCES))
SOURCES			= $(addprefix $(SRCFOLDER),$(_FILES_))
SOURCES			+= $(TEST_FILES)

TEST_OBJ		= $(SOURCES:.c=.o)

LIBS				= -L $(DIRPATH)/libft -lft -lcheck -ltermcap
INCLUDES			= -I $(DIRPATH)/includes/ -I $(DIRPATH)/libft/includes -I ./includes -I /Users/oyagci/.brew/include 

all: $(NAME)

$(NAME): $(TEST_OBJ)
	@echo 'Linking $(NAME)'
	@$(CC) $(CFLAGS) $(OBJ) $(TEST_OBJ) -o $(NAME) -L /Users/oyagci/.brew/lib $(LIBS) $(INCLUDES)

%.o: %.c
	@echo 'Building $<'
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm $(TEST_OBJ)

fclean: clean
	rm $(NAME)

re: fclean all
