/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 15:06:14 by jkettani          #+#    #+#             */
/*   Updated: 2019/04/18 15:09:17 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERTION_SORT_H
# define INSERTION_SORT_H

# include "worker.h"

int			handle_first_part(t_stacks *stacks, int i_best, int i_next);
int			handle_second_part(t_stacks *stacks, int i_best, int i_next);

#endif
