/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 16:27:21 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 23:26:40 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dstc;
	unsigned char	*srcc;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dstc = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (i < n)
	{
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}

static char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	size = ft_strlen((char *)s1);
	ptr = malloc((size + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, size);
	ptr[size] = '\0';
	return (ptr);
}

char	*ft_paths(char *cmd, char **envm)
{
	char	**paths;
	char	*path;
	size_t		i;
	size_t count_strings;
	char	*part_path;

	i = 0;
	count_strings = 0;
	while (envm[i] && ft_strnstr(envm[i], "PATH", 4) == 0)
		i++;
	if (!envm[i])
		return (ft_strdup(cmd));


	paths = ft_split(envm[i] + 5,':',&count_strings);

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
		{
			i = 0;
			while(paths[i])
				free(paths[i++]);
			free(paths);
			return (path);
		}
		free(path);
		i++;
	}
	i = 0;
	while(paths[i])
		free(paths[i++]);
	free(paths);
	return (ft_strdup(cmd));
}

