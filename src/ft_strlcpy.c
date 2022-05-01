/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:18:13 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 02:19:52 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (src == NULL)
		return (0);
	if (size > 0)
	{
		while (*src && (size--) - 1)
			*dst++ = *src++;
		*(dst) = '\0';
	}
	return (len_src);
}


