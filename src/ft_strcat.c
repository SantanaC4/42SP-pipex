/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:32:54 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 02:09:38 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_strcat(char *path, char *command)
{
	char *fullPath = (char*)malloc(sizeof(char)*(ft_strlen(path)+ft_strlen(command)));
	size_t i;


	if (fullPath == NULL)
		return 0;

	i = 0;
	while(*path)
		fullPath[i++] = *path++;
	while(*command)
		fullPath[i++] = *command++;
	return fullPath;
}
