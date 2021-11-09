/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:31:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/11/09 14:17:08 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Timeout doit être mis à 300000 pour que çca fonctionne sur tous les tests.

static char	*show_line(char **s, char **line, int fd)
{
	int		len;
	char	*tmp;

	if (fd < 0)
		return (NULL);
	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n' && (*s)[len + 1] != '\0')
	{
		*line = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (*line);
}

//BUFFER_SIZE = malloc(sizeof(char) * BUFFER_SIZE);
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str[FD_SIZE];
	char		*tmp;
	char		*line;
	int			ret;

	ret = 1;
	while (ret > 0 && fd >= 0)
	{
		ret = read (fd, buf, BUFFER_SIZE);
		if ((ret == 0 && str[fd] == NULL) || ret < 0)
			return (NULL);
		buf[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str[fd], buf);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (show_line(&str[fd], &line, fd));
}

/*int main()
{
	int 		fd;
	
	fd = open("42.txt", O_RDONLY);
	
	while(get_next_line(fd))
	{	
		get_next_line(fd);
	}
}*/