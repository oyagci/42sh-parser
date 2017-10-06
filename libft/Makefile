# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:27:13 by oyagci            #+#    #+#              #
#    Updated: 2017/10/04 16:10:31 by oyagci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g

OBJDIR		= objs
SRCDIR		= srcs
DEPSDIR		= includes

SOURCES_RAW	= ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
			  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
			  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
			  ft_putchar_fd.c ft_putchar.c ft_putstr.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putendl.c ft_memset.c ft_bzero.c ft_memcpy.c \
			  ft_memmove.c ft_memchr.c ft_memccpy.c ft_memcmp.c ft_strdup.c \
			  ft_strlen.c ft_strcmp.c ft_strncpy.c ft_strcpy.c ft_strcat.c \
			  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
			  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isupper.c ft_islower.c \
			  ft_strcjoin.c \
			  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_tolower.c ft_toupper.c ft_putnbr_fd.c ft_putnbr.c ft_itoa.c \
			  ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
			  ft_lstiter.c ft_lstmap.c ft_lstmap.c ft_abs.c ft_strupper.c \
			  ft_strlower.c get_next_line.c ft_lstpush_filter.c ft_getopt.c \
			  ft_lstpush.c ft_stradd.c ft_isspace.c ft_strjoin_at.c ft_strndup.c \
			  ft_dlstadd.c ft_dlstnew.c ft_dlstdelone.c ft_dlstdel.c \
			  ft_dlstpush.c ft_strcdup.c ft_dlstcount.c ft_lstrev.c ft_lstcount.c \
			  ft_lststr.c ft_strsplit_free.c ft_lstdel2.c
OBJECTS_RAW	= $(SOURCES_RAW:.c=.o)
DEPS_RAW	= libft.h libft_mem.h libft_list.h libft_str.h

SOURCES		= $(addprefix $(SRCDIR)/,$(SOURCES_RAW))
OBJECTS		= $(addprefix $(OBJDIR)/,$(OBJECTS_RAW))
DEPS		= $(addprefix $(DEPSDIR)/,$(DEPS_RAW))

INCLUDES	= -I./includes/

NAME		= libft.a

# ============================================================================ #

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJECTS) $(DEPS)
	@echo "Creating $(NAME)"
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Done $(NAME)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "Building $<"
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES)

clean:
	@$(RM) $(OBJECTS)
	@$(RM) -R $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
