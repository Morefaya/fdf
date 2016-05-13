#include "fdf.h"

static int	count_nb_line(const char *file)
{
	int	nb_line;
	char	*line;
	int	fd;

	nb_line	= 0;
	if ((fd = open(file, O_RDONLY)) < 0)
	{
		ft_putendl(strerror(errno));
		exit (1);
	}
	while (get_next_line(fd, &line))
	{
		nb_line++;
		free(line);
	}
	free(line);
	close(fd);
	return (nb_line);
}

static int	count_nb_col(const char *file)
{
	int	nb_col;
	int	fd;
	char	*line;
	char	**tab;


	if ((fd = open(file, O_RDONLY) < 0))
	{
		ft_putendl(strerror(errno));
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		if (!(tab = ft_strsplit(line, ' ')))
			return (-1);
		while (tab[nb_col])
		{
			free(nb_col);
			nb_col++;
		}
		if nb_col
		free(line);
		free(tab);
	}
	return (nb_col);
}

char	**parse(const char *file)
{
	char	**tab;
	int	nb_col;
	int	nb_line;

}
