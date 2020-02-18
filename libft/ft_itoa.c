/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsibanyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:35:49 by bsibanyo          #+#    #+#             */
/*   Updated: 2020/02/18 11:09:21 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_num_len(int n)
{
	size_t			length;

	length = 1;
	while (n /= 10)
		length++;
	return (length);
}

char				*ft_itoa(int n)
{
	char			*str;
	size_t			length;
	unsigned int	number;

	length = get_num_len(n);
	number = n;
	if (n < 0)
	{
		number = -n;
		length++;
	}
	if (!(str = ft_strnew(length)))
		return (NULL);
	str[--length] = number % 10 + '0';
	while (number /= 10)
		str[--length] = number % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
