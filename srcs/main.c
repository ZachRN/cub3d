#include "cub3d.h"


/*Headers here for testing but may (possibly) be removed later*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_cubed cube;
	if (argc != 2)
		return (0);
	cube.floor.r = 255;
	printf("%d\n", cube.floor.r); // quick struct test just to push something
	//in a non empty repo
	(void)argv; // Just getting rid of -werror atm with this
	return (0);
}