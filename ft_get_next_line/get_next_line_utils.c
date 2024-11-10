#include "get_next_line.h"

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
	int		size;
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

char *ft_read_and_append(int fd, char *st_buffer, char *buffer)
{
    int bytes_read;
    while ((bytes_read = read (fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        st_buffer = ft_strjoin(st_buffer, buffer);
        if (ft_strchr(st_buffer, '\n'))//can be optimized to search only the new part
            break;
    }
    return (st_buffer);
}

char *ft_copy_until_new_line(char *st_buffer, char *line)
{
    int i = 0;
    while (st_buffer[i] && st_buffer[i] != '\n')
    {
        line[i] = st_buffer[i];
        i++;
    }
    if (st_buffer[i] == '\n')
        line[i] = '\n';
    return (line);
}
