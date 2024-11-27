#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*copy(char *new, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(size + 1);
	if (new == NULL)
		return (NULL);
	new[size] = '\0';
	return (copy(new, (char *)s1, (char *)s2));
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	return (-1);
}


char *ft_read_and_append(int fd, char *st_buffer, char *buffer)
{
    int bytes_read;

	bytes_read = read (fd, buffer, BUFFER_SIZE);
    while (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
		if(st_buffer == NULL)
			st_buffer = ft_strjoin("", buffer);
		else
        	st_buffer = ft_strjoin(st_buffer, buffer);
		if (st_buffer == NULL)
			return (NULL);
        if (ft_strchr(st_buffer, '\n') == -1)
            bytes_read = read (fd, buffer, BUFFER_SIZE);
		else
			break;
    }
    return (st_buffer);
}

char *ft_copy_until_new_line(char *st_buffer, char *line)
{
    int		len;
    int		i;

	len = 0;
	while (st_buffer[len] && st_buffer[len] != '\n')
		len++;
	if (st_buffer[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return NULL;
	i = 0;
    while (st_buffer[i] && st_buffer[i] != '\n')
    {
        line[i] = st_buffer[i];
        i++;
    }
    if (st_buffer[i] == '\n')
	{
		line[i] = '\n';
	}
	line[++i] = '\0';
    return (line);
}

char	*ft_copy_after_newline(char *st_buffer)
{
	int		i;
	int		j;
	char	*new_st_buffer;

	i = 0;
	j = 0;
	while (st_buffer[i] && st_buffer[i] != '\n')
		i++;
	if (st_buffer[i] == '\n')
		i++;
	
	new_st_buffer = malloc(ft_strlen(st_buffer) - i + 1);
	if (!new_st_buffer)
		return (free(st_buffer), st_buffer = NULL, new_st_buffer);
	while (st_buffer[i])
	{
		new_st_buffer[j] = st_buffer[i];
		i++;
		j++;
	}
	new_st_buffer[j] = '\0';
	
	return (free(st_buffer), st_buffer = NULL, new_st_buffer);
}
