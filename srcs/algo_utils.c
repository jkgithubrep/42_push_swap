/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:40:22 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 14:58:23 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo_utils.h"
#include "list_utils.h"
#include "list_utils_2.h"
#include "list_utils_3.h"
#include "error.h"
#include "actions.h"
#include <stdlib.h>

int				apply_and_save_action(t_stacks *stacks, char *action_name)
{
	t_fptr		action;
	size_t		content_size;
	t_list		*new_elm;

	content_size = ft_strlen(action_name) + 1;
	if (!(action = get_action(action_name, content_size)))
		return (E_NULL);
	action(stacks);
	if (!(new_elm = ft_lstnew(action_name, content_size)))
		return (E_NULL);
	ft_lstadd(&stacks->actions, new_elm);
	return (EXIT_SUCCESS);
}

int				index_last_value_under_median(t_list *stack, int median)
{
	int			index;
	int			count;

	index = 0;
	count = 0;
	while (stack)
	{
		if (get_value(stack) < median)
			index = count;
		++count;
		stack = stack->next;
	}
	return (index);
}

int				index_last_value_above_median(t_list *stack, int median)
{
	int			index;
	int			count;

	index = 0;
	count = 0;
	while (stack)
	{
		if (get_value(stack) >= median)
			index = count;
		++count;
		stack = stack->next;
	}
	return (index);
}

int				index_next_value(t_list *stack, int value_ref, int size)
{
	int			index;
	int			last_next;
	int			count;

	count = 0;
	index = size - 1;
	last_next = get_max(stack);
	while (stack)
	{
		if (get_value(stack) > value_ref && get_value(stack) <= last_next)
		{
			index = count;
			last_next = get_value(stack);
		}
		if (!stack->next && index == count && get_value(stack) < value_ref)
			return (-1);
		++count;
		stack = stack->next;
	}
	return (index);
}

int				get_index_min(t_list *stack)
{
	int			i;

	i = 0;
	while (stack)
	{
		if (get_index(stack) == 0)
			return (i);
		++i;
		stack = stack->next;
	}
	return (EXIT_FAIL);
}
