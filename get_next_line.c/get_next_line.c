/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:07:29 by mohchaib          #+#    #+#             */
/*   Updated: 2024/11/07 23:04:40 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *st_buffer = NULL;
	char *buffer = NULL;
	char *line = NULL;
	if (fd < 0 || read(fd, NULL, 0) <= 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	st_buffer = ft_read_and_append();//call a function that handles the st_buffer
	if (!st_buffer)
		return NULL;
	line = ft_copy_until_newline();//call a function that handles the line
	st_buffer = ft_copy_after_newline();//call a function that handles the st_buffer
	return line;
}

int main ()
{
	int fd = open("text.txt", O_RDWR | O_CREAT  , 0777);
	if (fd < 0)
		return 1;
	write(fd, "amine\ntest\namine" , 16);
	char * str = get_next_line(fd);
	close(fd);
}