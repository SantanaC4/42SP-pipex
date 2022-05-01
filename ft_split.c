#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char **ft_split2(char *string, char *seperators, int *count);

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

char **ft_split2(char *string, char *seperators, int *count)
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
