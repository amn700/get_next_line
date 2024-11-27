#include "get_next_line.h"

char * get_next_line(int fd)
{
    char            buffer[BUFFER_SIZE + 1];
    static char     *st_buffer = NULL;
    char            *line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
    {
        return (NULL);
    }

    st_buffer = ft_read_and_append(fd, st_buffer, buffer);

    if (st_buffer == NULL)
    {
        return (NULL);
    }

    line = ft_copy_until_new_line(st_buffer, line);

    if (line == NULL)
    {
        return (free(st_buffer), st_buffer = NULL, NULL);
    }
    // printf("a\n");
    //copy l5ra somewhere then free st_buffer and join them
	st_buffer = ft_copy_after_newline(st_buffer);
    if (st_buffer == NULL)
    {
        return (NULL);
    }
    // printf("a\n");
    return (line);
}

// int main ()
// {
//     static char    *st_buffer = NULL;
//     char           *line = NULL;
//     char           *buffer = NULL;

//     int fd = open("test.txt", O_RDONLY);
//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (0);

//     buffer = malloc(BUFFER_SIZE + 1);
//     if (buffer == NULL)
//         return (0);
//     // int i = 0;
//     // while (i < BUFFER_SIZE)
//     // {
//     //     buffer[i] = 'a';
//     //     i++;
//     // }
//     // buffer[BUFFER_SIZE] = '\0';
//     // printf("%s\n%i\n", buffer , i);

//     st_buffer = ft_read_and_append(fd, st_buffer, buffer);
//     // printf("%s\n", st_buffer);
//     if (st_buffer == NULL)
//         return (0);

//     line = ft_copy_until_new_line(st_buffer, line);
//     printf("%s\n", line);
//     st_buffer = ft_copy_after_newline(st_buffer);
//     printf("%s\n", st_buffer);
//     // close(fd);
//     return (0);
// }
