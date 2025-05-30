/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:52:58 by imugica-          #+#    #+#             */
/*   Updated: 2025/01/14 15:47:53 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*next_ft_strchr(char *string, int c)
{
	while (*string)
	{
		if (*string == (unsigned char)c)
			return ((char *)string);
		string++;
	}
	if (c == '\0')
		return (0);
	return (0);
}

int	ft_check_null(int bytes, char **rem, char **buffer)
{
	if ((bytes <= 0) && !*rem)
	{
		free(*buffer);
		free(*rem);
		return (1);
	}
	return (0);
}

char	*trim_newline(char **str1)
{
	char	*newline_pos;
	size_t	length;
	char	*trimmed_str;

	newline_pos = next_ft_strchr(*str1, '\n');
	if (newline_pos == NULL)
		return (ft_free_return(str1));
	length = next_ft_strlen(newline_pos + 1);
	trimmed_str = (char *)malloc(length + 1);
	if (trimmed_str == NULL)
		return (ft_free_return(str1));
	else if (!length)
	{
		free(trimmed_str);
		return (ft_free_return(str1));
	}
	ft_memcpy(trimmed_str, newline_pos + 1, length);
	free(*str1);
	trimmed_str[length] = '\0';
	return (trimmed_str);
}

char	*ft_clean(char **rem)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (*(*rem + len) != '\n' && *(*rem + len))
		len++;
	str = malloc(len + 2);
	if (!str || (len == 0 && *(*rem + len) != '\n'))
	{
		free(str);
		return (0);
	}
	while (*(*rem + i) != '\n' && *(*rem + i))
	{
		str[i] = *(*rem + i);
		i++;
	}
	if (*(*rem + i))
		str[i++] = '\n';
	str[i] = '\0';
	*rem = trim_newline(rem);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*rem = NULL;
	char		*buffer;
	int			bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (fd == -1 || !BUFFER_SIZE || !buffer)
		return (ft_free_return(&buffer));
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (ft_check_null(bytes, &rem, &buffer))
		return (0);
	buffer[bytes] = '\0';
	if (bytes)
	{
		rem = next_ft_strjoin(&rem, buffer, bytes);
		while (!next_ft_strchr(rem, '\n') && bytes && bytes == BUFFER_SIZE)
		{
			bytes = read(fd, buffer, BUFFER_SIZE);
			ft_sanity_buffer(buffer, bytes);
			if (bytes)
				rem = next_ft_strjoin(&rem, buffer, bytes);
		}
	}
	free(buffer);
	buffer = 0;
	return (ft_clean(&rem));
}
