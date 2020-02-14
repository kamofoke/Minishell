/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsibanyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:46:25 by bsibanyo          #+#    #+#             */
/*   Updated: 2019/06/21 20:04:09 by bsibanyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
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

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("system:%zu\n", strlcat(argv[1], argv[2], strlen(argv[1])));
		printf("ft_:%zu", ft_strlcat(argv[1], argv[2],ft_strlen(argv[1])));
	}
}
