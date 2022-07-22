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
while (y < texHeight)
    {
        x = 0;
        while (x < texWidth)
		{
			//ptr = &(math->pngtex[pos + texHeight * y + x]);
			printf("___________________________________________________________________\n");
			if (x != 0)
			{
				math->pngtex[pos] = math->pngtex[pos] + prev_color[0];
				math->pngtex[pos + 1] = math->pngtex[pos + 1] + prev_color[1];
				math->pngtex[pos + 2] = math->pngtex[pos + 2] + prev_color[2];
			}
			math->texture[5][texHeight * y + x] = getIntFromColor(math->pngtex[pos], math->pngtex[pos + 1], math->pngtex[pos + 2]);
			printf("\n\nr is %d, g is %d, b is %d\n\n", math->pngtex[pos], math->pngtex[pos + 1], math->pngtex[pos + 2]);
			printf("get big edian returns %d\n", getIntFromColor(math->pngtex[pos], math->pngtex[pos + 1], math->pngtex[pos + 2]));
			prev_color[0] = math->pngtex[pos];
			prev_color[1] = math->pngtex[pos + 1];
			prev_color[2] = math->pngtex[pos + 2];
			pos += 3;
			printf("____________________________TEST_________________________________\n");
			printf("\n\nr is %d, g is %d, b is %d\n\n", math->pngtex[pos], math->pngtex[pos + 1], math->pngtex[pos + 2]);
			if (x  == 4)
				exit(0);
			//printf("current point is %d\n", texHeight * y + x);
		//	printf("%d\n", math->pngtex[texHeight * y + (x + pos)]);
			//printf("get big edian returns %d", get_big_endian(ptr));
			//exit(0);
			x++;
			printf("____________________________________________________________________\n");
		}
		y++;
	}
    */

static int getIntFromColor(int Red, int Green, int Blue)
{
	int	color = Red * 65536 + Green * 256 + Blue;
    return (color); //0xFF000000 for 100% Alpha. Bitwise OR everything together.
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
	int	size;
	uint8_t	prev_color[3];
	int	color;
	//char line[texHeight * texWidth * 16]; http://jeromebelleman.gitlab.io/posts/devops/libpng/

	fd = open("pics/colorstonekeepresolution.png", fd);
	if (fd == -1)
	{
		printf("file error\n");
		exit(0);
	}
	ft_bzero(math->pngtex, texHeight * texWidth * 16);
	size = read(fd, math->pngtex, texHeight * texWidth * 16);
	close(fd);
	while (i < 200)
	{
		printf("%d index is %d\n", math->pngtex[i], i);
		i++;
	}
	printf("size is %d", size);
	pos = 49;
	pos = 70;
	prev_color[0] = math->pngtex[pos];
	prev_color[1] = math->pngtex[pos + 1];
	prev_color[2] = math->pngtex[pos + 2];
	prev_color[0] = 0;
	prev_color[1] = 0;
	prev_color[2] = 0;
	y = 0;
	while (y < texHeight)
    {
        x = 0;
        while (x < texWidth)
		{
			color = getIntFromColor(math->pngtex[pos] + prev_color[0], math->pngtex[pos + 1] + prev_color[1], math->pngtex[pos + 2] + prev_color[2]);
			if (y >= 2)
				color = INT_MAX;
			math->texture[5][y * texHeight + x] = color;
			printf("\n\ncolor is %d\n\n", color);
			printf("prevcolor is %d, %d, %d\n", prev_color[0], prev_color[1], prev_color[2]);
			printf("Current color is %d, %d, %d x is %d\n", math->pngtex[pos], math->pngtex[pos + 1], math->pngtex[pos + 2], x);
			prev_color[0] = math->pngtex[pos] + prev_color[0];
			prev_color[1] = math->pngtex[pos + 1] + prev_color[1];
			prev_color[2] = math->pngtex[pos + 2] + prev_color[2];
			pos += 3;
			if (y == 2)
				exit(0);
			x++;
		}
		pos++;
		y++;
	}
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
