#include "wolf3d.h"

static void drawline(int x0, int y0, int x1, int y1, t_prm *prm)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int error = dx + dy;
    int e2;

    while (1)
    {
        printf("x0 = %d\nx1 = %d\n\n", x0, y0);
        ((unsigned int *)prm->mlx->image_add)[((prm->mlx->size_line / 4) * y0 + x0)] = INT_MAX;
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

void wolf3d(t_prm *prm)
{
    t_math *math;

    math = prm->math;
    int     x;

    x = 0;
    math->h = 100; // height of walls in pixel on screen
    math->w = 0.6;
    //calculate ray position and direction
    while (x < math->w)
    {
        //printf("test5\n\n");
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

        //choose wall color
        switch((*math->worldmap)[math->mapxy[X]][math->mapxy[Y]])
        {
            case 1:  math->color = INT_MAX;  break; //red
            case 2:  math->color = INT_MAX;  break; //green
            case 3:  math->color = INT_MAX;   break; //blue
            case 4:  math->color = INT_MAX;  break; //white
            default: math->color = INT_MAX; break; //yellow
        }

        //give x and y sides different brightness
        /*if (math->side == 1)
        {
            math->color = math->color / 2;
        }*/

        //draw the pixels of the stripe as a vertical line
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
        }
        //drawline(x, math->drawstart, x, math->drawend, prm);
        x++;
    }
    math->time = time(NULL);
    math->frames++;
    if (math->time > math->oldtime)
    {
        math->oldtime = math->time;
        printf("fps is %d\n", math->frames);
        math->frames = 0;
    }
   // math->oldtime = math->time;
    math->movespeed = math->frames * 5;
    math->rotspeed = math->frames * 3;
}
