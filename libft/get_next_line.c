/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaine <vlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:06:50 by vlaine            #+#    #+#             */
/*   Updated: 2022/04/14 22:15:15 by vlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_returnval(char **line, char **tab, int res)
{
	if (res == -1)
		return (-1);
	if (*tab != NULL)
	{
		*line = ft_strdup(*tab);
		ft_strdel(&(*tab));
	}
	else
	{
		*line = NULL;
		return (0);
	}
	return (1);
}

static void	ft_read_buffsize(char **c, char **tab)
{
	size_t		index;

	if (*tab == NULL)
		*tab = ft_strnew(BUFF_SIZE);
	index = 0;
	while ((*c)[index] && (*c)[index] != '\n')
		index++;
	if ((*c)[index] != '\n')
		index = BUFF_SIZE;
	*tab = ft_realloc(&(*tab), (ft_strlen(*tab) + index));
	ft_strncat(*tab, (*c), index++);
	if (ft_strchris(*c, '\n', BUFF_SIZE) == 1)
		ft_memmove(*c, (*c + index), (ft_strlen(*c)));
}

static int	ft_valuetoline(const int fd, char **tab, char **c)
{
	int			isfound;
	int			res;

	isfound = 0;
	res = 1;
	while (isfound == 0 && res > 0)
	{
		ft_bzero(*c, BUFF_SIZE);
		res = read(fd, (*c), BUFF_SIZE);
		isfound = ft_strchris(*c, '\n', BUFF_SIZE);
		if (res > 0)
			ft_read_buffsize(&(*c), &(*tab));
		if (res == -1)
		{
			ft_strdel(&(*c));
			ft_strdel(&(*tab));
			return (-1);
		}
	}
	if (isfound == 0)
		ft_strdel(&(*c));
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*c[8192];
	char		*tab;
	int			isfound;

	if (fd < 0 || line == NULL || fd >= 8192 || BUFF_SIZE < 1)
		return (-1);
	if (c[fd] == NULL)
		c[fd] = ft_strnew(BUFF_SIZE);
	tab = NULL;
	isfound = 0;
	if (ft_strlen(c[fd]) > 0 && c[fd][0])
	{
		isfound = ft_strchris(c[fd], '\n', BUFF_SIZE);
		ft_read_buffsize(&(c[fd]), &tab);
	}
	if (isfound == 0)
	{
		if (ft_valuetoline(fd, &tab, &(c[fd])) == -1)
			return (ft_returnval(&(*line), &tab, -1));
	}
	return (ft_returnval(&(*line), &tab, 1));
}
