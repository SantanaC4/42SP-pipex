/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:01:27 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 02:19:47 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **ft_split(char *string, char *seperators, int *count)
{
	int len = ft_strlen(string);

	*count = 0;

	int i = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (ft_strchr(seperators,string[i]) == NULL)
				break;
			i++;
		}

		int old_i = i;
		while(i < len)
		{
			if (ft_strchr(seperators,string[i]) != NULL)
				break;
			i++;
		}

		if (i > old_i)
			*count = *count + 1;
	}

	char **strings = malloc(sizeof(char *) * *count);

	i = 0;
	int string_index = 0;
	char buffer[21341];
	while (i < len)
	{
		while (i < len)
		{
			if (ft_strchr(seperators, string[i]) == NULL)
				break;
			i++;
		}

		int j = 0;
		while(i < len)
		{
			if (ft_strchr(seperators, string[i]) != NULL)
				break;

			buffer[j] = string[i];
			i++;
			j++;
		}

		if (j > 0)
		{
			buffer[j] = '\0';

			int to_allocate;

			to_allocate = sizeof(char) * (ft_strlen(buffer) + 1);
			strings[string_index] = malloc(to_allocate);
			strcpy(strings[string_index], buffer);
			string_index++;
		}
}
return strings;
}
