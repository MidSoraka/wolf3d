#include "wolf3d.h"

int main()
{
    t_prm prm;
    t_mlx mlx;

    prm.mlx = &mlx;
    create_window(&prm);
    return (0);
}
