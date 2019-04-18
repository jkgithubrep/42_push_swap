/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:36:57 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/11 15:51:52 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_UTILS_2_H
# define LIST_UTILS_2_H

# include "libft.h"
# include "worker.h"

int				lst_elm_cmp_block_equal(t_node *node, int	*block_ref);
int				lst_elm_cmp_block_not_equal(t_node *node, int	*block_ref);
void			lst_elm_max(void *content, void *ret);
void			lst_elm_min(void *content, void *ret);
void			lst_elm_max_digits(void *content, void *ret);

#endif
