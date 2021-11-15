
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//#include "j12.h"

#define BUFFER_SIZE 10


int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

void	ft_putchar1(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb >= 0 && nb < 10)
	{
		ft_putchar(nb + 48);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int main()
{
	int fd;
	int ret;  // permet de stocker le retour de READ
	char buf[BUFFER_SIZE + 1]; //Important de mettre +1 afin de laisser place au nul-terminated. Il va copier 10 bytes jusqu'à atteindre
	/* char buf[] = pointeur sur char qui prend la grosseur du buffer(10) + 1 
	pour pouvoir storer le nul-terminated 0;*/
	fd = open("42", O_RDONLY | O_CREAT | O_APPEND , S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE))) 
	{
		buf[ret]  = '\0'; 
		ft_putnbr(ret);
		ft_putstr(buf);
	} // Lorsqu'on imprime , il y a toujours un "0" qui est imprimé pour indiquer la fin de la lecture du fichier. 
	printf("\n");
	ft_putnbr(ret);
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}