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
    */
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
            math->texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
            math->texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
            math->texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
            y++;
        }
        x++;
    }
    printf("\n\ntesting\n\n");
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
