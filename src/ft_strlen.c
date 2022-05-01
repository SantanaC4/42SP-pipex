/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 01:27:06 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 01:31:06 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_strlen(const char *str)
{
	int count;

	if (str == NULL)
		return 0;

	count = 0;
	while(*str++)
		count++;
	return count;
}
