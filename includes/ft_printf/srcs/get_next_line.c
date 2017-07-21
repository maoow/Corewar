/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:18:54 by cbinet            #+#    #+#             */
/*   Updated: 2017/06/26 16:41:21 by cbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char		*ft_read(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	int		i;
	int		j;

	i = 0;
	ret = BUFF_SIZE;
	str = NULL;
	while (ret == BUFF_SIZE && ft_strchr(str, '\n') == NULL)
	{
		j = 0;
		ret = read(fd, buf, BUFF_SIZE);
		if (ret >= 0)
		{
			str = ft_strrealloc(str, ret);
			while (j < ret)
				str[i++] = buf[j++];
			str[i] = '\0';
		}
	}
	return (str);
}

static char		*ft_delfirstline(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i])
		i++;
	dst = ft_strdup(str + i);
	free(str);
	return (dst);
}

static void		ft_getline(char *str, char **dst)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	*dst = (char *)malloc((i + 1) * sizeof(**dst));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		(*dst)[i] = str[i];
		i++;
	}
	(*dst)[i] = '\0';
}

static t_list	*ft_initlist(t_list **lst, int fd)
{
	t_list	*tmp;

	if (*lst == NULL)
		*lst = ft_lstnew("", sizeof(char));
	while (ft_lstlen(*lst) <= fd + 1)
		ft_lstaddend(lst, ft_lstnew("", sizeof(char)));
	tmp = ft_lstgoto(*lst, fd + 1);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	char			*str;

	if (line == NULL || read(fd, NULL, 0) == -1)
		return (-1);
	tmp = ft_initlist(&lst, fd);
	if (ft_strcmp(tmp->content, "") == 0 || !ft_strchr(tmp->content, '\n'))
	{
		str = ft_read(fd);
		str = ft_strjoinfree((char **)&(tmp->content), &str, SECOND);
		ft_lstreplace(&lst, ft_lstnew(str, (1 + ft_strlen(str)) *
					sizeof(char)), fd + 1);
		free(str);
	}
	tmp = ft_lstgoto(lst, fd + 1);
	if (ft_strcmp(tmp->content, "") == 0 || tmp->content == NULL)
		return (0);
	str = ft_strdup(tmp->content);
	ft_getline(str, line);
	str = ft_delfirstline(str);
	ft_lstreplace(&lst, ft_lstnew(str, (1 + ft_strlen(str)) *
				sizeof(char)), fd + 1);
	free(str);
	return (1);
}
