/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: invite <invite@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:31:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/11/08 15:19:27 by invite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*show_line(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n' && (*s)[len + 1] != '\0')
	{
		*line = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		//if ((*s)[0] == '\0')
		//{
			//free(*s);
			//*s = NULL;
		//}
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*str[FD_SIZE];
	char		*tmp;
	char		*line;
	int			ret;

	line = NULL; //Why is this line removable?
	if (fd < 0)
		return (NULL);
	while ((ret = read (fd, buf, BUFFER_SIZE)) > 0)
	{
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
	if ((ret == 0 && str[fd] == NULL) || ret < 0)
		return (NULL);
	//if (ret < 0)
		//return (NULL);
	return (show_line(&str[fd], &line));
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