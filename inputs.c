#include "wolf3d.h"

int keyboard_input(int key, void *ptr)
{
    printf("key is %d\n", key);
    if (key == 65307)
        exit(0);
    return (0);
}

int mouse_input(int key, void *ptr)
{

    return (0);
}
