#include "wolf3d.h"

static void drawline(int x0, int y0, int x1, int y1, t_prm *prm)
{
    t_math *math;

    math = prm->math;
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;
    int e2;

    while (1)
    {
        //printf("x0 = %d\nx1 = %d\n\n", x0, y0);
        ((unsigned int *)prm->mlx->image_add)[((prm->mlx->size_line / 4) * y0 + x0)] = math->color;
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break;
            error = error + dy;
            x0 = x0 + sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break;
            error = error + dx;
            y0 = y0 + sy;
        }
    }
}

static void raycasting(t_prm *prm, int x)
{
    t_math *math;

    math = prm->math;
    math->camerax = 2 * x / (double)(math->w) - 1; //x-coordinate in camera space
    math->raydirxy[X] = math->dirxy[X] + math->planexy[X] * math->camerax;
    math->raydirxy[Y] = math->dirxy[Y] + math->planexy[Y] * math->camerax;
    math->mapxy[X] = (int)(math->posxy[X]);
    math->mapxy[Y] = (int)(math->posxy[Y]);
    if (math->raydirxy[X] == 0)
        math->deltadisxy[X] = (double)INT_MAX;
    else
        math->deltadisxy[X] = fabs(1 / math->raydirxy[X]);
    if (math->raydirxy[Y] == 0)
        math->deltadisxy[Y] = (double)INT_MAX;
    else
        math->deltadisxy[Y] = fabs(1 / math->raydirxy[Y]);
    math->hit = 0;
    if (math->raydirxy[X] < 0)
    {
        math->stepxy[X] = -1;
        math->sidedistxy[X] = (math->posxy[X] - math->mapxy[X]) * math->deltadisxy[X];
    }
    else
    {
        math->stepxy[X] = 1;
        math->sidedistxy[X] = (math->mapxy[X] + 1.0 - math->posxy[X]) * math->deltadisxy[X];
    }
    if (math->raydirxy[Y] < 0)
    {
        math->stepxy[Y] = -1;
        math->sidedistxy[Y] = (math->posxy[Y] - math->mapxy[Y]) * math->deltadisxy[Y];
    }
    else
    {
        math->stepxy[Y] = 1;
        math->sidedistxy[Y] = (math->mapxy[Y] + 1.0 - math->posxy[Y]) * math->deltadisxy[Y];
    }

    //perform DDA
    while (math->hit == 0)
    {
        //jump to next map square, either in x-direction, or in y-direction
        if (math->sidedistxy[X] < math->sidedistxy[Y])
        {
            math->sidedistxy[X] += math->deltadisxy[X];
            math->mapxy[X] += math->stepxy[X];
            math->side = 0;
        }
        else
        {
            math->sidedistxy[Y] += math->deltadisxy[Y];
            math->mapxy[Y] += math->stepxy[Y];
            math->side = 1;
        }
        //Check if ray has hit a wall
        if ((*math->worldmap)[math->mapxy[X]][math->mapxy[Y]] > 0)
            math->hit = 1;
    }

    //Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
    if(math->side == 0)
        math->perpwalldist = (math->sidedistxy[X] - math->deltadisxy[X]);
    else
        math->perpwalldist = (math->sidedistxy[Y] - math->deltadisxy[Y]);
    
    //Calculate height of line to draw on screen
    math->lineheight = (int)(math->h / math->perpwalldist);

    //calculate lowest and highest pixel to fill in current stripe
    math->drawstart = -math->lineheight / 2 + math->h / 2;
    if(math->drawstart < 0)
        math->drawstart = 0;
    math->drawend = math->lineheight / 2 + math->h / 2;
    if(math->drawend >= math->h)
        math->drawend = math->h - 1;

    //texturing calculations
    int texNum = (*math->worldmap)[math->mapxy[X]][math->mapxy[Y]] - 1; //1 subtracted from it so that texture 0 can be used!

    //calculate value of wallX
    double wallX; //where exactly the wall was hit
    if (math->side == 0)
        wallX = math->posxy[Y] + math->perpwalldist * math->raydirxy[Y];
    else
        wallX = math->posxy[X] + math->perpwalldist * math->raydirxy[X];
    wallX -= floor((wallX)); // floor is used to convert double to integer or at least closer to integer

    //x coordinate on the texture
    int texX = ((int)(wallX * ((double)(texWidth))));
    if(math->side == 0 && math->raydirxy[X] > 0)
        texX = texWidth - texX - 1;
    if(math->side == 1 && math->raydirxy[Y] < 0)
        texX = texWidth - texX - 1;

    // How much to increase the texture coordinate per screen pixel
    double step = 1.0 * texHeight / math->lineheight;
    // Starting texture coordinate
    double texPos = (math->drawstart - math->h / 2 + math->lineheight / 2) * step;
    int y = math->drawstart;

    printf("\n\ntesting99\n\n");
    while (y < math->drawend)
    {
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        math->color = math->texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(math->side == 1)
            math->color = (math->color >> 1) & 8355711;
      //  math->color = 128 + 256 * 128 + 65536 * 128;
        ((unsigned int *)prm->mlx->image_add)[((prm->mlx->size_line / 4) * y + x)] = math->color;
        //buffer[y][x] = color;
        y++;
    }
    printf("\n\ntesting88\n\n");
    /*
    //choose wall color
    switch((*math->worldmap)[math->mapxy[X]][math->mapxy[Y]])
    {
        case 1:  math->color = 0xFF0000;  break; //red 0xFF0000
        case 2:  math->color = 0x00FF00;  break; //green
        case 3:  math->color = 0x0000FF;   break; //blue 0x0000FF
        case 4:  math->color = INT_MAX;  break; //white
        default: math->color = 0xFFFF00; break; //yellow
    }

    //give x and y sides different brightness
    if (math->side == 1)
    {
        math->color = math->color / 2;
    }

    //draw the pixels of the stripe as a vertical line
    /*
    if (abs(math->drawend - math->drawstart) < abs(x - x))
    {
        if (x > x)
            drawline(x, math->drawend, x, math->drawstart, prm);
        else
            drawline(x, math->drawstart, x, math->drawend, prm);
    }
    else
    {
        if (math->drawstart > math->drawend)
            drawline(x, math->drawend, x, math->drawstart, prm);
        else
            drawline(x, math->drawstart, x, math->drawend, prm);
    }*/
    //drawline(x, math->drawstart, x, math->drawend, prm);
}

void wolf3d(t_prm *prm)
{
    t_math *math;

    math = prm->math;
    int     x;

    x = 0;
    math->h = screenHeight; // height of walls in pixel on screen
    math->w = screenWidth;
    //calculate ray position and direction
    math->oldtime = clock();
    while (x < math->w)
        raycasting(prm, x++);
    math->time = clock();
    math->deltatime += math->oldtime - math->time;
    math->frames++;
    if ((math->deltatime/(double)CLOCKS_PER_SEC) > 1000.0)
    {
        math->frametime = (double)math->frames*0.5 + math->frametime * 0.5;
        math->frames = 0;
        math->deltatime -= CLOCKS_PER_SEC;
        if (math->frametime == 0)
            math->frametime = 0.001;
        printf("fps is %f\n", 1000.0/math->frametime);
    }
   // math->oldtime = math->time;
    math->movespeed = 0.8;
    math->rotspeed = 0.3;
}
