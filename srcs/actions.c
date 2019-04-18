/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:07:39 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 18:19:35 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "worker.h"
#include "libft.h"
#include "error.h"
#include "push.h"
#include "swap.h"
#include "rotate.h"
#include "reverse_rotate.h"
#include "print_utils.h"
#include "list_utils.h"
#include <stdlib.h>
#include <unistd.h>

t_fptr			get_action(char *line, int ret)
{
	int						i;
	static const t_actions	actions[] = {{"sa", &sa}, {"sb", &sb}, {"ss", &ss},
		{"ss", &ss}, {"pa", &pa}, {"pb", &pb}, {"ra", &ra}, {"rb", &rb},
		{"rr", &rr}, {"rra", &rra}, {"rrb", &rrb}, {"rrr", &rrr}, {NULL, NULL}};

	i = -1;
	while (actions[++i].name)
		if (!ft_memcmp(line, actions[i].name, ret))
			return (actions[i].f);
	return (NULL);
}

int				get_actions_from_stdin(t_stacks *stacks)
{
	t_fptr		action;
	int			ret;
	int			newline;
	size_t		count;
	char		*line;

	newline = 0;
	line = NULL;
	action = NULL;
	count = 1;
	while ((ret = ft_secure_gnl(STDIN_FILENO, &line, &newline, 10000)) >= 0)
	{
		if (ret < 2 || ret > 3 || !newline || !line[ret - 1])
			return (ft_strdel_ret(&line, E_INVALID_CMD));
		if (!(action = get_action(line, ret)))
			return (ft_strdel_ret(&line, E_INVALID_CMD));
		action(stacks);
		if (stacks->flags & FL_VISU)
			print_stacks(stacks, line, count);
		++count;
		ft_strdel(&line);
	}
	if (ret < -1 || (action && !newline))
		return (ft_strdel_ret(&line, E_INVALID_CMD));
	return (ft_strdel_ret(&line, EXIT_OK));
}

int				should_be_removed(char *action, char *next_action)
{
	if ((!ft_strcmp(action, "pb") && !ft_strcmp(next_action, "pa"))
			|| (!ft_strcmp(action, "pa") && !ft_strcmp(next_action, "pb"))
			|| (!ft_strcmp(action, "ra") && !ft_strcmp(next_action, "rra"))
			|| (!ft_strcmp(action, "rra") && !ft_strcmp(next_action, "ra"))
			|| (!ft_strcmp(action, "ra") && !ft_strcmp(next_action, "rra"))
			|| (!ft_strcmp(action, "rra") && !ft_strcmp(next_action, "ra")))
		return (1);
	return (0);
}

int				actions_lst_optimize(char *action, char *next_action)
{
	if (should_be_removed(action, next_action))
		return (1);
	else if ((!ft_strcmp(action, "ra") && !ft_strcmp(next_action, "rb"))
			|| (!ft_strcmp(action, "rb") && !ft_strcmp(next_action, "ra")))
	{
		ft_printf("%s\n", "rr");
		return (1);
	}
	else if ((!ft_strcmp(action, "sa") && !ft_strcmp(next_action, "sb"))
		|| (!ft_strcmp(action, "sb") && !ft_strcmp(next_action, "sa")))
	{
		ft_printf("%s\n", "ss");
		return (1);
	}
	else if ((!ft_strcmp(action, "rra") && !ft_strcmp(next_action, "rrb"))
		|| (!ft_strcmp(action, "rrb") && !ft_strcmp(next_action, "rra")))
	{
		ft_printf("%s\n", "rrr");
		return (1);
	}
	return (0);
}

void			print_actions_list(t_list **actions)
{
	t_list		*lst;

	if (!actions || !*actions)
		return ;
	ft_lstrev(actions);
	lst = *actions;
	while (lst)
	{
		if (lst->next && actions_lst_optimize(lst->content, lst->next->content))
			lst = lst->next;
		else
			ft_printf("%s\n", (char *)lst->content);
		if (lst)
			lst = lst->next;
	}
}
