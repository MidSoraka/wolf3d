#include "wolf3d.h"

int keyboard_input(int key, void *ptr)
{
    t_prm *prm;
    t_math *math;

    prm = ((t_prm *) ptr);
    math = prm->math;
    printf("key is %d\n", key);
    if (key == 65307)
        exit(0);
    else if (key == 65362) // up
    {
        if((*math->worldmap)[(int)(math->posxy[X] + math->dirxy[X] * math->movespeed)][(int)math->posxy[Y]] == 0) 
            math->posxy[X] += math->dirxy[X] * math->movespeed;
        if((*math->worldmap)[(int)(math->posxy[X])][(int)(math->posxy[Y] + math->dirxy[Y] * math->movespeed)] == 0)
            math->posxy[Y] += math->dirxy[Y] * math->movespeed;
    }
    else if (key == 65364) // down
    {
        if((*math->worldmap)[(int)(math->posxy[X] - math->dirxy[X] * math->movespeed)][(int)(math->posxy[Y])] == 0)
            math->posxy[X] -= math->dirxy[X] * math->movespeed;
        if((*math->worldmap)[(int)(math->posxy[X])][(int)(math->posxy[Y] - math->dirxy[Y] * math->movespeed)] == 0)
            math->posxy[Y] -= math->dirxy[Y] * math->movespeed;
    }
    else if (key == 65363) // right
    {
        double oldDirX = math->dirxy[X];
        math->dirxy[X] = math->dirxy[X] * cos(-math->rotspeed) - math->dirxy[Y] * sin(-math->rotspeed);
        math->dirxy[Y] = oldDirX * sin(-math->rotspeed) + math->dirxy[Y] * cos(-math->rotspeed);
        double oldPlaneX = math->planexy[X];
        math->planexy[X] = math->planexy[X] * cos(-math->rotspeed) - math->planexy[Y] * sin(-math->rotspeed);
        math->planexy[Y] = oldPlaneX * sin(-math->rotspeed) + math->planexy[Y] * cos(-math->rotspeed);
    }
    else if (key == 65361) // left
    {
        //both camera direction and camera plane must be rotated
        double oldDirX = math->dirxy[X];
        math->dirxy[X] = math->dirxy[X] * cos(math->rotspeed) - math->dirxy[Y] * sin(math->rotspeed);
        math->dirxy[Y] = oldDirX * sin(math->rotspeed) + math->dirxy[Y] * cos(math->rotspeed);
        double oldPlaneX = math->planexy[X];
        math->planexy[X] = math->planexy[X] * cos(math->rotspeed) - math->planexy[Y] * sin(math->rotspeed);
        math->planexy[Y] = oldPlaneX * sin(math->rotspeed) + math->planexy[Y] * cos(math->rotspeed);
    }
    return (0);
}

int mouse_input(int key, void *ptr)
{
    t_prm *prm;
    prm = ((t_prm *) ptr);
    return (0);
}
