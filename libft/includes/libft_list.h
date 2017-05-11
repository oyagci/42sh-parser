/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:58:44 by oyagci            #+#    #+#             */
/*   Updated: 2017/04/10 14:16:57 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include <string.h>

typedef struct			s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}						t_list;

typedef	struct s_dlist	t_dlist;
struct					s_dlist
{
	void		*content;
	size_t		content_size;
	t_dlist		*prev;
	t_dlist		*next;
};

t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst,
							void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstpush_filter(
							t_list *lst,
							void *content, size_t content_size,
							int (*f)(t_list *, void *, size_t));
void					ft_lstpush(t_list **list, t_list *elem);
t_list					*ft_lstlast(t_list *lst);
char					**ft_lststr(t_list *lst);
size_t					ft_lstcount(t_list *lst);

t_dlist					*ft_dlstnew(void const *content, size_t content_size);
void					ft_dlstdelone(t_dlist **alst,
							void (*del)(void *, size_t));
void					ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
void					ft_dlstadd(t_dlist **alst, t_dlist *elem);
void					ft_dlstpush(t_dlist **alst, t_dlist *elem);
size_t					ft_dlstcount(t_dlist *lst);

#endif
