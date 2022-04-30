#include <stdlib.h>


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

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cast;
	unsigned char	*src_cast;

	dest_cast = (unsigned char *)dest;
	src_cast = (unsigned char *)src;
	while (n--)
		*dest_cast++ = *src_cast++;
	return (dest);
}

static char	*ft_strdup(const char *s)
{
	char	*n;

	n = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s, ft_strlen(s) + 1);
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*n;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	n = malloc((len + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	ft_strlcpy(n, s + start, len + 1);
	return (n);
}

static char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
		if (*str++ == '\0')
			return (NULL);
	return ((char *)str);
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
	*words = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**words;

	if (s == NULL)
		return (NULL);
	word_count = count_words(s, c);
	words = malloc(sizeof(char **) * (word_count + 1));
	if (words == NULL)
		return (NULL);
	create_words(words, s, c, word_count);
	return (words);
}
