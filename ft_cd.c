/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamofoke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 07:55:55 by kamofoke          #+#    #+#             */
/*   Updated: 2020/02/21 10:36:02 by kamofoke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir(char *home_path)
{
	char	*cwd;
	char	buff[4096];

	cwd = getcwd(buff, 4096);
	if (chdir(home_path) == 0)
		set_envp("OLDPWD", cwd);
	else
	{
		ft_putstr("cd: ");
		ft_putstr(home_path);
		if (access(home_path, F_OK) == -1)
			ft_putendl(": no such file or directory");
		else if (access(home_path, R_OK) == -1)
			ft_putendl(": you don't have permission");
		else
			ft_putendl(": not a directory");
	}
}

static char	*ft_move(char *path)
{
	path++;
	path++;
	return (path);
}

static void	view_home(char *home_path, char *path)
{
	char	*temp;
	char	*temp2;

	temp = ft_strjoin(home_path, "/");
	temp2 = ft_strjoin(temp, ft_move(path));
	change_dir(temp2);
	free(temp);
	free(temp2);
}

int			ft_cd(char **arg)
{
	char	*home_path;

	home_path = find_envp("HOME");
	if (!arg[0] || (arg[0][0] == '~' && !arg[0][1]))
	{
		change_dir(home_path);
		return (1);
	}
	else
	{
		if (arg[0][0] == '~' && arg[0][1] == '/')
		{
			view_home(home_path, arg[0]);
			return (1);
		}
		else if (arg[0][0] == '-' && !arg[0][1])
		{
			change_dir(find_envp("OLDPWD"));
			return (1);
		}
		change_dir(arg[0]);
	}
	return (1);
}
