#ifndef WOLF3D_H
# define WOLF3D_H

# include "stdio.h"
# include "mlx/Linux/mlx.h"

typedef struct s_prm
{
	struct s_mlx		*mlx;
}				t_prm;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image_ptr;
	char		*image_add;
	int			size_line;
	int			erdian;
	int			bpp;
}				t_mlx;

void wolf3d(t_prm *prm);
void create_window(t_prm *prm);
int mouse_input(int key, void *ptr);
int keyboard_input(int key, void *ptr);

#endif
