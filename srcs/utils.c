/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:18:53 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/23 15:56:38 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "list_utils.h"
#include "print_utils.h"
#include "worker.h"
#include "libft.h"

void			del_all(t_stacks *stacks)
{
	ft_lstdel(&stacks->stack_a, &lst_elm_del);
	ft_lstdel(&stacks->stack_b, &lst_elm_del);
	ft_lstdel(&stacks->actions, &lst_elm_del);
	ft_secure_gnl(-1, NULL, NULL, 1000);
}

int				exit_fail(t_stacks *stacks, int err_no)
{
	del_all(stacks);
	print_err(err_no, stacks->flags);
	return (-1);
}
