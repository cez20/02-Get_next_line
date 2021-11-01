/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:31:04 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/11/01 08:58:09 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1- Calling GNL in loop will allow to read text available of FD oneline at a time until end of it
	2 -Make sure file GNL behave well when read from a FILE, and when it reads from STANDARD INPUT
	3 -Program must compile with flag gcc -Wall -Wextra -Werror -D BUFFER_SIZE = 42 <files> .c
	4 -Use READ, MALLOC AND FREE,
	5 -Your READ must use the BUFFER SIZE defined during compilation to read from file or from stdin.
*/
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	str[BUFFER_SIZE + 1];
	char	*str1;
	int		ret;
	int 	i;

	i = 0;
	if (fd == -1) // si le file descriptor est un fichier qu'on ne peut lire, retourne NULL: 
		return (NULL);
	str1 = alloc_mem(str);
	while ((ret = read (fd, str1, BUFFER_SIZE) > 0))
	{
		if (ret == -1) 
			return (NULL);
		str1[ret - 1] = '\n'; // à changer, il devrait imprimer 8 caractère, le 9eme devrait etre un saut de ligne et le 10e backslash \0'
		str1[ret]  = '\0'; 
		ft_putnbr(ret);
		ft_putstr(str1);
	}
	if (ret == 0) // Condition qui dit si fd retourne  0(fin du fichier) ou si ret == -1 en cas d'erreur)
	{
		ft_putstr("NO MORE CONTENT\n");
		return (NULL);
	}		
	printf("\n");
	ft_putnbr(ret);

	return (str1);
}

int main()
{
	int fd;

	fd = open("42", O_RDONLY | O_CREAT | O_APPEND , S_IRUSR);
	get_next_line(fd);
}