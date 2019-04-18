/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:54:11 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/10 19:09:18 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_utils_3.h"
#include "list_utils_2.h"
#include "worker.h"

int				get_value(t_list *stack)
{
	return (((t_node *)stack->content)->value);
}

int				get_block(t_list *stack)
{
	return (((t_node *)stack->content)->block);
}

void			update_block(t_list *stack, int value)
{
	((t_node *)stack->content)->block = value;
}

int				get_min(t_list *stack)
{
	int			min;

	min = get_value(stack);
	ft_lstget(stack, &min, &lst_elm_min);
	return (min);
}

int				get_max(t_list *stack)
{
	int			max;

	max = get_value(stack);
	ft_lstget(stack, &max, &lst_elm_max);
	return (max);
}
