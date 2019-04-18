/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:48:23 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 13:09:57 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils.h"
#include "worker.h"
#include "libft.h"

int				lst_elm_compare(const t_node *node1, const t_node *node2)
{
	return (node1->value - node2->value);
}

int				lst_elm_ordered(t_node *node1, t_node *node2)
{
	if (node1->value <= node2->value)
		return (1);
	else
		return (0);
}

t_list			*lst_elm_cpy(t_list *elm)
{
	return (ft_lstnew(elm->content, elm->content_size));
}

void			lst_elm_del(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}

int				get_index(t_list *stack)
{
	return (((t_node *)stack->content)->index);
}
