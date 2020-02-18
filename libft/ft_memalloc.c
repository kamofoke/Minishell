/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsibanyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:02:40 by bsibanyo          #+#    #+#             */
/*   Updated: 2019/06/20 09:09:05 by bsibanyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!size)
		return (0);
	mem = malloc(size);
	if (mem == NULL)
	{
		return (NULL);
	}
	ft_bzero(mem, size);
	return (mem);
}
