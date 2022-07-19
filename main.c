#include "wolf3d.h"

/*
while (x < texWidth)
    {
        while (y < texHeight)
        {
            xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
            ycolor = y * 256 / texHeight;
            xycolor = y * 128 / texHeight + x * 128 / texWidth;
            math->texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
            math->texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
            math->texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
            math->texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
            math->texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
            math->texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
            math->texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
            math->texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
            y++;
        }
        x++;
    }
	static void read_texture(t_math *math)
{
	int x;
	int y;

	y = 0;
	while (y < texHeight)
    {
        x = 0;
        while (x < texWidth)
		{
			math->pngtex[texHeight * y + x] = INT_MAX;
			printf("current point is %d\n", texHeight * y + x);
			x++;
		}
		y++;
	}
}
static void read_texture(t_math *math)
{
	int x;
	int y;

	x = 0;
	while (x < texWidth)
    {
        y = 0;
        while (y < texHeight)	
		{
			math->pngtex[texWidth * y + x] = INT_MAX;
			printf("current point is %d\n", texWidth * y + x);
			y++;
		}
		x++;
	}
}
    */

static int getIntFromColor(int Red, int Green, int Blue)
{
    return (Blue * 65536 + Green * 256 + Red); //0xFF000000 for 100% Alpha. Bitwise OR everything together.
}

static int get_big_endian(char *buf)
{
	int	test[4];
	int	increment = 128;
	//printf("buf 0123 0=%d, 1=%d, 2=%d, 3=%d\n", buf[0], buf[1], buf[2], buf[3]);
	test[0] = buf[0] + increment;
	test[1] = buf[1] + increment;
	test[2] = buf[2] + increment;
	test[3] = buf[3] + increment;
	//printf("after buf 0123 0=%d, 1=%d, 2=%d, 3=%d\n", test[0], test[1], test[2], test[3]);
	return (test[3] * 65536 + test[2] * 256 + test[1]);
}

static void read_texture(t_math *math)
{
	int x;
	int y;
	int	fd;
	int	pos;
	int	*ptr;
	int i = 0;
	int	res;
	//char line[texHeight * texWidth * 16]; http://jeromebelleman.gitlab.io/posts/devops/libpng/

	fd = open("pics/colorstone.png", fd);
	if (fd == -1)
	{
		printf("file error\n");
		exit(0);
	}
	res = read(fd, math->pngtex, texHeight * texWidth);
	pos = 8;
	y = 0;
	// x = 3 y = 0 color is = 4732952
	while (math->pngtex[i])
	{
		printf("%d index is %d\n", math->pngtex[i], i);
		i++;
	}
	printf("nubmer is %d\n", texHeight * texWidth);
	exit(0);
	while (y < texHeight)
    {
        x = 0;
        while (x < texWidth)
		{
			ptr = &(math->pngtex[pos + texHeight * y + x]);
			math->texture[5][texHeight * y + x] = math->pngtex[texHeight * y + x];
			//printf("current point is %d\n", texHeight * y + x);
			printf("%d\n", math->pngtex[texHeight * y + (x + pos)]);
			//printf("get big edian returns %d", get_big_endian(ptr));
			//exit(0);
			pos += 4;
			x++;
		}
		y++;
	}
	exit(0);
}

static void default_math(t_math *math)
{
    int x;
    int y;
    int xorcolor;
    int ycolor;
    int xycolor;

    x = 0;
    y = 0;
    math->posxy[X] = 22;
    math->posxy[Y] = 12;
    math->dirxy[X] = -1;
    math->dirxy[Y] = 0;
    math->planexy[X] = 0;
    math->planexy[Y] = 0.66;
    math->time = 0;
    math->oldtime = 0;
	read_texture(math);
    while (x < texWidth)
    {
        y = 0;
        while (y < texHeight)
        {
            xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
            ycolor = y * 256 / texHeight;
            xycolor = y * 128 / texHeight + x * 128 / texWidth;
            math->texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
            math->texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
            math->texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
            math->texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
            math->texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
            //math->texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
            math->texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
            math->texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture

			//math->texture[5][texWidth * y + x] = math->pngtex[texWidth * y + x];
            y++;
        }
        x++;
    }
}

int main()
{
    int defaultMap[mapWidth][mapHeight]=
    {
    {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
    {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
    {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
    {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
    {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
    {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
    {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
    {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
    {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
    {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
    {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
    {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
    {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
    {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
    {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
    {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
    {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
    {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
    {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
    {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
    {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
    };
    t_prm prm;
    t_mlx mlx;
    t_math math;
    clock_t now = clock();

    ft_bzero(&prm, sizeof(t_prm));
    ft_bzero(&mlx, sizeof(t_mlx));
    ft_bzero(&math, sizeof(t_math));
    math.worldmap = &defaultMap;
    prm.math = &math;
    prm.mlx = &mlx;
    math.oldtime = now;
   // printf("22 1 is %f\n", math.time);
    default_math(&math);
    create_window(&prm);
    return (0);
}
