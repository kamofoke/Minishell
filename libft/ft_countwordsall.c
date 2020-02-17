/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwordsall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:13:44 by kamofoke          #+#    #+#             */
/*   Updated: 2020/02/17 08:28:06 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwordsall(char const *str)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (IS_SPACE(str[i]))
			i++;
		if (!IS_SPACE(str[i]) && str[i] != '\0')
			count++;
		while (!IS_SPACE(str[i]) && str[i] != '\0')
			i++;
	}
	return (count);
}
