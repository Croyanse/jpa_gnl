/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:50:01 by jpaterno          #+#    #+#             */
/*   Updated: 2021/09/21 13:50:02 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	char	*str;

	if (!s2 || !s1)
		return (NULL);
	str = (char *)s1;
	if (*s1 == '\0')
		return (ft_strdup(s2));
	ptr = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (*str != '\0')
		*ptr++ = *str++;
	str = (char *)s2;
	while (*str != '\0')
		*ptr++ = *str++;
	*ptr = '\0';
	ptr = ptr - (ft_strlen(s1) + ft_strlen(s2));
	free(s1);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;

	new = malloc(size * count);
	if (!(new))
		return (NULL);
	ft_memset(new, 0, count * size);
	return (new);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		count;
	int		size;

	size = 0;
	while (s1[size])
		++size;
	dest = malloc(sizeof(char) * (size + 1));
	if (!(dest))
		return (NULL);
	count = 0;
	while (s1[count])
	{
		dest[count] = (char)s1[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
