/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 02:01:27 by edrodrig          #+#    #+#             */
/*   Updated: 2022/05/01 22:55:38 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (!s)
		return ((void *)0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	res = malloc(sizeof(char) * (len + 1));
	if (res == (void *)0)
		return ((void *)0);
	while (i < len)
	{
		if (s[start + i] != '\0' && start < ft_strlen(s))
			res[i] = s[start + i];
		else
			res[i] = '\0';
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	count_words(char const *s, char c)
{
	size_t	word_count;
	size_t	skipper;

	word_count = 0;
	skipper = 1;
	while (*s)
	{
		if (*s != c && skipper)
		{
			skipper = 0;
			word_count++;
		}
		else if (*s++ == c)
			skipper = 1;
	}
	return (word_count);
}

static char const	*skip_equal_chars(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return (s);
}

static void	create_words(
	char	**words, char const *s, char c, size_t word_count)
{
	char	*pointerator;

	s = skip_equal_chars(s, c);
	while (word_count--)
	{
		pointerator = ft_strchr(s, c);
		if (pointerator != NULL)
		{
			*words = ft_substr(s, 0, pointerator - s);
			s = skip_equal_chars(pointerator, c);
		}
		else
			*words = ft_substr(s, 0, ft_strlen(s) + 1);
		words++;
	}
	*words = (void*)0;
}

char	**ft_split(char const *s, char c, size_t *count)
{
	size_t	word_count;
	char	**words;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	*count = word_count;
	words = malloc(sizeof(char **) * (word_count + 1));
	if (words == NULL)
		return (NULL);
	create_words(words, s, c, word_count);
	return (words);
}
