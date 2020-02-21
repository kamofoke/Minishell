/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 10:32:24 by kamofoke          #+#    #+#             */
/*   Updated: 2020/02/21 10:37:12 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	echo_path(char *arg)
{
	char	*path;

	path = find_envp(arg + 1);
	ft_putstr(path);
}

static void	echo_str(char *arg)
{
	int		len;
	int		start;
	int		end;

	len = (int)ft_strlen(arg);
	start = 0;
	end = len - 1;
	if (arg[0] == '$')
		echo_path(arg);
	else
	{
		while (arg[start] == '\'' || arg[start] == '"')
			start++;
		while (arg[end] == '\'' || arg[end] == '"')
			end--;
		while (start <= end)
			write(1, &arg[start++], 1);
	}
}

int			ft_echo(char **arg)
{
	int		i;

	i = 0;
	if (!arg[0])
	{
		write(1, "\n", 1);
		return (1);
	}
	while (arg[i])
	{
		echo_str(arg[i]);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
	return (1);
}
