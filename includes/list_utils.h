/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:52:25 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 13:10:17 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_H
# define LIST_UTILS_H

# include "worker.h"

int				get_index(t_list *stack);
int				lst_elm_compare(const t_node *node1, const t_node *node2);
int				lst_elm_ordered(t_node *node1, t_node *node2);
t_list			*lst_elm_cpy(t_list *elm);
void			lst_elm_del(void *content, size_t size);

#endif
