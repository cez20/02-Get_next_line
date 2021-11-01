/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 11:49:03 by cemenjiv          #+#    #+#             */
/*   Updated: 2021/10/29 15:17:14 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This file must contain AT LEAST the prototype of the function get_next_line. In other words
it may contain other prototype*/
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putstr_fd(char *s, int fd);
char	*alloc_mem(char *s);

#endif