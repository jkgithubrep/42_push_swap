/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:19:17 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/12 12:53:21 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "worker.h"
#include "libft.h"
#include "error.h"

static int		update_flag(char c, t_uint *flags)
{
	if (c == 'v')
		*flags |= FL_VISU;
	else if (c == 'e')
		*flags |= FL_ERR;
	else if (c == 's')
		*flags |= FL_SLOW;
	else if (c == 'f')
		*flags |= FL_FAST;
	else if (c == 'h')
		*flags |= FL_HELP;
	else
		return (E_INVALID_FLAG);
	return (EXIT_OK);
}

static int		get_flags(int ac, char **av, int *i, t_uint *flags)
{
	int			j;

	while ((*i) < ac)
	{
		if ((av[*i][0] == '-') && av[*i][1] && !ft_isdigit(av[*i][1]))
		{
			j = 0;
			while (av[*i][++j])
				if (update_flag(av[*i][j], flags))
					return (E_INVALID_FLAG);
		}
		else if ((av[*i][0] == '-') && !av[*i][1])
			return (E_INVALID_FLAG);
		else
			return (EXIT_OK);
		++(*i);
	}
	return (EXIT_OK);
}

static int		save_arg_value(char *value, t_stacks *stacks)
{
	int			nb;
	t_node		node;
	t_list		*elm;

	if (ft_atois(value, &nb))
		return (E_OVERFLOW);
	node.value = nb;
	node.block = 0;
	node.index = 0;
	if (!(elm = ft_lstnew(&node, sizeof(node))))
		return (E_NULL);
	ft_lstadd(&stacks->stack_a, elm);
	++(stacks->size_a);
	return (EXIT_OK);
}

static int		parse_arg(char *arg, t_stacks *stacks)
{
	int			i;
	int			value_start;

	i = 0;
	while (arg[i])
	{
		while (arg[i] && ft_isblank(arg[i]))
			++i;
		if (!arg[i])
			break ;
		if (!(ft_isdigit(arg[i]) || ft_issign(arg[i]))
				|| (ft_issign(arg[i]) && !ft_isdigit(arg[i + 1])))
			return (E_INVALID_ARG);
		value_start = i++;
		while (ft_isdigit(arg[i]))
			++i;
		if (arg[i] && !ft_isblank(arg[i]))
			return (E_INVALID_ARG);
		else if (arg[i])
			++i;
		if (save_arg_value(arg + value_start, stacks))
			return (E_OVERFLOW);
	}
	return (EXIT_OK);
}

int				parse_args_list(int ac, char **av, t_stacks *stacks)
{
	int			i;
	int			ret;

	i = 1;
	if (stacks->flags & FL_CHECKER)
		if ((ret = get_flags(ac, av, &i, &stacks->flags)))
			return (ret);
	if (stacks->flags & FL_HELP)
		return (E_HELP);
	if (i >= ac)
		return (E_NBR_ARGS);
	while (i < ac)
	{
		if ((ret = parse_arg(av[i], stacks)))
			return (ret);
		++i;
	}
	return (EXIT_OK);
}
