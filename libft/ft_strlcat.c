/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsibanyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:46:25 by bsibanyo          #+#    #+#             */
/*   Updated: 2020/02/20 10:43:24 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
	{
		i++;
	}
	while (src[j] != '\0' && ((i + j + 1) < dstsize))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
