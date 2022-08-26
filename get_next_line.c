/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:24:24 by jpaterno          #+#    #+#             */
/*   Updated: 2021/10/01 19:24:28 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void	*iis_ns(char c, char *str, int choice, char *s)
{
	int		i;

	if (choice == 0)
	{
		while (*str)
		{
			if (*str == c)
				return ("true");
			str++;
		}
		return (NULL);
	}
	str = NULL;
	i = 0;
	while (s[i++] != '\n')
		;
	if (s[i] != '\0')
		str = ft_strdup(&s[i]);
	free (s);
	return (str);
}

char	*nlinsave(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != '\n')
		i++;
	if (i == 0)
		i = 1;
	str = malloc ((i + 2) * sizeof(char));
	if (!str)
	{
		free (s);
		return (NULL);
	}
	i = 0;
	while (s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = s[i];
	str[i + 1] = '\0';
	return (str);
}

int	create_save(char *buff, char **save)
{
	int		i;
	int		ix;
	char	*str;

	ix = 0;
	i = 0;
	while (buff[i++] != '\n')
		;
	if (buff[i])
	{
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!str)
			return (0);
	}
	while (buff[i] && str)
		str[ix++] = buff[i++];
	buff[i - ix] = '\0';
	*save = str;
	return (1);
}

char	*ft_gnl(int fd, char *str, char **save, char *buff)
{
	while (!(iis_ns('\n', str, 0, NULL)))
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			free (str);
		if (read(fd, buff, BUFFER_SIZE) <= 0)
		{
			if (buff)
				free(buff);
			if (*str)
				return (str);
			return (NULL);
		}
		if (iis_ns('\n', buff, 0, NULL))
			if (create_save(buff, &(*save)) == 0)
				free (str);
		str = ft_strjoin(str, buff);
		free (buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*save;
	char		*buff;

	buff = NULL;
	str = "";
	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	if (save)
	{
		if (iis_ns('\n', save, 0, NULL))
		{
			str = nlinsave(save);
			save = iis_ns('.', ".", 1, save);
			return (str);
		}
		str = ft_strjoin(save, str);
		save = NULL;
	}
	return (ft_gnl(fd, str, &save, buff));
}
