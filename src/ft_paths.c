/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:27:21 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 17:06:57 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_paths(char *cmd, char **envm)
{
	char	**paths;
	char	*path;
	int		i;
	int count_strings;
	char	*part_path;

	i = 0;
	count_strings = 0;
	while (ft_strnstr(envm[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envm[i] + 5,":",&count_strings);
	i = 0;
	while (i < count_strings)
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		i++;
	}
	return (0);
}

