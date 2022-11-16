/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: znajda <znajda@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 12:07:28 by znajda        #+#    #+#                 */
/*   Updated: 2022/11/16 12:16:03 by znajda        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"
#include "get_next_line.h"
#include "cub3d_errors.h"

char	*send_new_line(int fd, t_filehold *file, int pos)
{
	char	*temp;
	int		strlen;

	temp = (char *)malloc(sizeof(char) * pos + 2);
	if (!temp)
	{
		free(file->all_fd[fd]);
		two_strings_error(MALLOC_ERROR, "get_next_line.c; line 23");
	}
	ft_strlcpy(temp, file->all_fd[fd], pos + 2);
	strlen = ft_strlen(file->all_fd[fd]);
	ft_strlcpy(file->all_fd[fd], &file->all_fd[fd][pos + 1], strlen - pos + 1);
	return (temp);
}

char	*send_EOF(int fd, t_filehold *file, int pos)
{
	char	*temp;

	if (file->all_fd[fd][0])
	{
		temp = (char *)malloc(sizeof(char) * pos + 2);
		if (!temp)
		{
			free(file->all_fd[fd]);
			two_strings_error(MALLOC_ERROR, "get_next_line.c; line 41");
		}
		ft_strlcpy(temp, file->all_fd[fd], pos + 2);
		free(file->all_fd[fd]);
		file->all_fd[fd] = NULL;
		return (temp);
	}
	if (file->all_fd[fd])
		free(file->all_fd[fd]);
	return (NULL);
}

char	*file_stuff(t_filehold *file, int fd)
{
	int		pos;

	pos = 0;
	while (file->all_fd[fd][pos] != '\n' && file->all_fd[fd][pos] != '\0')
		pos++;
	if (file->all_fd[fd][pos] == '\n')
		return (send_new_line(fd, file, pos));
	else
		return (send_EOF(fd, file, pos));
}

int	process_next_line(int fd, t_filehold *files, int readbytes)
{
	char	*temp;

	files->buf[readbytes] = '\0';
	temp = ft_strjoin(files->all_fd[fd], files->buf);
	if (!temp)
	{
		free(files->all_fd[fd]);
		two_strings_error(MALLOC_ERROR, "get_next_line.c; line 75");
	}
	free(files->all_fd[fd]);
	files->all_fd[fd] = temp;
	return (1);
}

char	*get_next_line(int fd)
{
	static t_filehold	files;
	int					readbytes;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FD_TOTAL)
		two_strings_error(FILE_ERROR, "get_next_line.c; line 92");
	files.buf[0] = '\0';
	readbytes = read(fd, files.buf, BUFFER_SIZE);
	if (!files.all_fd[fd] && readbytes > 0)
		files.all_fd[fd] = ft_strdup("\0");
	if (!files.all_fd[fd])
		return (NULL);
	while (readbytes != 0)
	{
		if (!process_next_line(fd, &files, readbytes))
			return (NULL);
		if (ft_strchr(files.all_fd[fd], '\n') || files.all_fd[fd][0] == '\0')
			break ;
		readbytes = read(fd, files.buf, BUFFER_SIZE);
	}
	return (file_stuff(&files, fd));
}
