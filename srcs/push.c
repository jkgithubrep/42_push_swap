/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:42:42 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/05 14:48:49 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "worker.h"
#include "libft.h"

static void		push(t_list **src, t_list **dest)
{
	t_list *tmp;

	if (!src || !dest || !*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void			pa(t_stacks *stacks)
{
	push(&stacks->stack_b, &stacks->stack_a);
	if (stacks->size_b)
	{
		--(stacks->size_b);
		++(stacks->size_a);
	}
}

void			pb(t_stacks *stacks)
{
	push(&stacks->stack_a, &stacks->stack_b);
	if (stacks->size_a)
	{
		--(stacks->size_a);
		++(stacks->size_b);
	}
}
