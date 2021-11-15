/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:29:42 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/10/26 16:39:35 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//#include "j12.h"

void	ft_putchar1(int fd, char *str)
{
	write(fd, str, strlen(str));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

int main()
{
	int fd;

	fd = open("alph.txt", O_WRONLY | O_CREAT | O_APPEND , S_IRUSR | S_IWUSR);
	ft_putnbr(fd);
	ft_putchar1 (fd, "Hello world ! \n");
	printf("\n");
	
	return (0);
}