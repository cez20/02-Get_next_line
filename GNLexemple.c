#include "get_next_line.h"

/*
** This function appends a single line into our line variable. We do this by
** finding the length of the line. If at index len, the character is a newline,
** we save the string into line up to the length found. Then we readjust the
** stored data (**s) by creating a temporary string that stored the rest of data
** after the newline. We free the stored data to update it to the current
** address because we already append a line from it. This is done by freeing *s
** and setting it equal to the temporary string that stored the remaining data.
** At any point when we reach the end of the file, we free the memory used to
** track our location in *s because it is not needed anymore.
*/

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

/*
** This is a helper function created to output the results after all the other
** cases are taken care of in get_next_line. For example, if ret is less than 0,
** then return -1 since an error occurred. If the reading is completed, return a
** 0. Else, go to appendline function to return 1 and save the line read at the
** current address of the static variable stored.
*/

static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

/*
** The get_next_line function reads a file and returns the line ending with a
** newline character from a file descriptor. A static variable is used, so that
** whenever get_next_line is called, it remembers the previous function call.
** When get_next_line is first called, we check to see if our static variable
** **s is empty. If it is, we allocate memory for it using our buff string.
** In the loop, we will continue to read more of the line and join them together
** using a temporary string. This temporary string will replace the stored data
** each iteration so that we can keep track of how much is read and delete
** the previous stored data. This is needed because we are only reading so many
** n-bytes at a time decided by our BUFF_SIZE. If we read at each iteration
** without freeing memory, then we would have memory leaks. The loop breaks when
** a newline is encountered. Finally, we call output function to check what
** should be returned.
*/

int			get_next_line(const int fd, char **line)
{
	int			ret; // le ret calcule la longueur de ce qui doit être copié. Si on met BUFFER_SIZE = 42 , il affichera 42. 
	static char	*s[FD_SIZE]; // FD size a été assigné à 4096 dans le get_next_line.h 
	char		buff[BUFF_SIZE + 1]; //Ceci est la chaine de caractère qui reçoit la texte àa écrire. Cette string est toujours écrasé de nouveau. 
	char		*tmp; //String temporaire pour STORER des éléments. 

	if (fd < 0 || line == NULL) // Chaque file descript a un numéro d'assigné. Dans am fonction. Si fd = -1 , return (NULL);
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0) // Si ret retourne 0, c'est qu'il n'y a plus de caractèeres àa lire. Tant est aussi longtemps que ret est plus grand que 0;
	{
		buff[ret] = '\0'; // buf[10] si le BUFF size est à 10. On met un backslash 0 pour finir le string est indiqué sa fin. 
		if (s[fd] == NULL) // si s[3] (3 correspond au file descriptor) ne contient aucune adresse (absence d'adresse). Difficile àa comprendre pour moi. 
			s[fd] = ft_strdup(buff); // We duplicate te content of string BUFF in s[fd] in which the memory was allocated dynamically with malloc 
		else
		{
			tmp = ft_strjoin(s[fd], buff); // string temporaire TMP, va contenir la chaine de caractère s[fd] à laquelle on ajoute la chaine de caractèere buff. 
			free(s[fd]); //On libèere le contenu de s[fd] et on le remplace par l'équivalent de s[fd] + BUFF. En d'autres mots, cette chaîne va sans cesse croitre. 
			// Je ne crois pas que l'usage de free ici est bon, car le pointeur sur char "s" n'a pas été eu de la mémoire avec malloc SAUF si la façcon dont c'est declaré ici-haut signie que c'est declré dynamiquement
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n')) //Si la fonction qui recherche le caractère /n est donne "1" comme quoi le caractèere est trouvé 
			break ; //fait un break et arrête de copier du contenu. 
	}
	return (output(s, line, ret, fd));
}