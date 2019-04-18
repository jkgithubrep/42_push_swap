/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:31:55 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/11 19:02:25 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils_2.h"
#include "worker.h"

int			lst_elm_cmp_block_equal(t_node *node, int *block_ref)
{
	return (node->block - *block_ref);
}

int			lst_elm_cmp_block_not_equal(t_node *node, int *block_ref)
{
	return (!(node->block - *block_ref));
}

void		lst_elm_max(void *content, void *ret)
{
	*((int *)ret) = ft_max(((t_node *)content)->value, *((int *)ret));
}

void		lst_elm_min(void *content, void *ret)
{
	*((int *)ret) = ft_min(((t_node *)content)->value, *((int *)ret));
}

void		lst_elm_max_digits(void *content, void *ret)
{
	*((int *)ret) = ft_max(ft_digits_base(((t_node *)content)->value, 10) + 1,
						*((int *)ret));
}
