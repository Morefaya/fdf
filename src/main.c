#include "fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*ptr_win;

	mlx_ptr = NULL;
	ptr_win = NULL;
	if (!(mlx_ptr = mlx_init()))
		ft_putstr("error init");
	if (!(ptr_win = mlx_new_window(mlx_ptr, 1000, 1000, "yolo")))
		ft_putstr("error new window");
	return (0);
}
