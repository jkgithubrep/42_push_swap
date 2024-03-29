/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprepend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkettani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:50:56 by jkettani          #+#    #+#             */
/*   Updated: 2019/03/20 16:50:58 by jkettani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strprepend(const char *prepend, char **str)
{
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = *str;
	*str = ft_strjoin(prepend, tmp);
	ft_strdel(&tmp);
	return (*str);
}
