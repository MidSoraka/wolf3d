#include "wolf3d.h"

static int window_loop(void *ptr)
{
    t_prm *prm;
    prm = ((t_prm *) ptr);
	wolf3d(prm);
    return (0);
}

void create_window(t_prm *prm)
{
    t_mlx *mlx;

    mlx = prm->mlx;
    mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1280, 1280, "win");
	mlx->image_ptr = mlx_new_image(mlx->mlx_ptr, 1280, 1280);
	mlx->image_add = \
	mlx_get_data_addr(mlx->image_ptr, &mlx->bpp, &mlx->size_line, &mlx->erdian);
	mlx_loop_hook(mlx->mlx_ptr, window_loop, prm);
	mlx_key_hook(mlx->win_ptr, keyboard_input, prm);
	mlx_mouse_hook(mlx->win_ptr, mouse_input, prm);
	mlx_loop(mlx->mlx_ptr);
}
