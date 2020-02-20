/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:52:22 by kamofoke          #+#    #+#             */
/*   Updated: 2020/02/20 10:52:50 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_setenv(char **arg)
{
	if (!arg[0] || (arg[0] && !arg[1]))
	{
		ft_putendl("setenv: \033[0mtoo few arguments\36m");
		return (1);
	}
	if (arg[0] && arg[1])
	{
		if (arg[2])
		{
			ft_putendl("setenv: \033[0mtoo many arguments\36m");
			return (1);
		}
		set_envp(arg[0], arg[1]);
	}
	return (1);
}
