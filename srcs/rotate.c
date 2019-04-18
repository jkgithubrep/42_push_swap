/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:32:28 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/05 14:48:49 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"
#include "worker.h"
#include "libft.h"

static void		rotate(t_list **stack)
{
	t_list		*last;
	t_list		*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	*stack = (*stack)->next;
	last->next = NULL;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
}

void			ra(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
}

void			rb(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
}

void			rr(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
}
