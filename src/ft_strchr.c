/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:12:49 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 02:13:03 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char ch;

	ch = c;
	while (*str != '\0')
    {
          if ((unsigned char)*str == ch)
			  return ((char*)str);
          str++;
    }
    return (NULL);
}
