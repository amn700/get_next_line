#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// #define BUFFER_SIZE 10

char    *get_next_line(int fd);
char    *ft_read_and_append(int fd, char *st_buffer, char *buffer);
char    *ft_copy_until_new_line(char *st_buffer, char *line);
char	*ft_copy_after_newline(char *st_buffer);
#endif