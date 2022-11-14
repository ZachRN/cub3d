#ifndef CUB3D_H
# define CUB3D_H

/*STDINT includes __uint8_t instead of saying unsigned char for the
floor and ceiling structs*/
#include <stdint.h>

/*This is to more easily parse the 2d map array given so that we may call
If Map[0][0] == Wall instead of Map[0][0] == 1, it brings a bit of clarity
and structure

NP is the only special character, which is non playable, it will fill
parts of the map in parsing, that are "empty" spaces but not walls within the
map

North, East, South, West, are all player character identifiers, only one
may exist on the map at a time, and this determines the orientation of the
player upon starting*/
enum mapDefintion
{
	nonPlayable = -1,
	empty = 0,
	wall = 1,
	north,
	east,
	south,
	west
};

/*Both the floor and the ceiling have identical structs. Seperated for clarity
as they are seperate entities. Both will be parsed to contain an
RGB value between 0-255 for each color respectfully.*/
typedef struct s_floor
{
	__uint8_t	r;
	__uint8_t	g;
	__uint8_t	b;
}				t_floor;

/*Both the floor and the ceiling have identical structs. Seperated for clarity
as they are seperate entities. Both will be parsed to contain an
RGB value between 0-255 for each color respectfully.*/
typedef struct s_ceiling
{
	__uint8_t	r;
	__uint8_t	g;
	__uint8_t	b;
}				t_ceiling;

/*This contains the path to each texture, one for each, north
east, south, west. Where the math section will then be able to open the
textures on their side to get the images.

This struct can be changed to hold open file descriptors if you wish instead */
typedef struct s_textures
{
	char	*north;
	char	*east;
	char	*south;
	char	*west;
}				t_textures;

/*This is the struct that contains all the information. Holding the
floor, ceiling, and texture structs. as well as containing the 2d array of
the parsed map.*/
typedef struct s_cubed
{
	t_floor		floor;
	t_ceiling	ceiling;
	t_textures	textures;
	char		**map;
}				t_cubed;

#endif
