/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:37:09 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/05 14:48:49 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reverse_rotate.h"
#include "worker.h"
#include "libft.h"

static void		reverse_rotate(t_list **stack)
{
	t_list		*head;
	t_list		*prev;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	head = *stack;
	while ((*stack)->next)
	{
		prev = *stack;
		*stack = (*stack)->next;
	}
	prev->next = NULL;
	(*stack)->next = head;
}

void			rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
}

void			rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_b);
}

void			rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	reverse_rotate(&stacks->stack_b);
}
