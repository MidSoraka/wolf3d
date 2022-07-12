#ifndef WOLF3D_H
# define WOLF3D_H

# include "stdio.h"
# include "mlx/Linux/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <time.h>

#define INT_MAX 2147483647
#define X 0
#define Y 1
#define Z 2
#define mapWidth 24 // all of these defines should be on caps
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64

typedef struct	s_prm
{
	struct s_math	*math;
	struct s_mlx	*mlx;
}				t_prm;

typedef struct	s_math
{
	int			(*worldmap)[mapWidth][mapHeight];
	double		posxy[2];
	double		dirxy[2];
	double		planexy[2];
	double		camerax;
	double		raydirxy[2];
	int			w; // change this
	int			mapxy[2];
	double		sidedistxy[2];
	double		deltadisxy[2];
	double		perpwalldist;
	int			stepxy[2];
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			h; //change this
	unsigned int			color;
	double		time;
	double		oldtime;
	int			frames;
	double		frametime;
	double		movespeed;
	double		rotspeed;
	clock_t		deltatime;
	unsigned int			texture[8][texHeight * texWidth];
}				t_math;

typedef struct	s_mlx
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
