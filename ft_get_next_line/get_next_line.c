#include "get_next_line.h"

char * get_next_line(int fd)
{
    static char    *st_buffer = NULL;
    char           *line = NULL;
    char           *buffer = NULL;

    buffer = malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
        return (NULL);
    st_buffer = ft_read_and_append(fd, st_buffer, buffer);
    if (st_buffer == NULL)
        return (NULL);
    line = ft_copy_until_new_line(st_buffer, line);
    
	st_buffer = ft_copy_after_newline();
    return (line);
}
