#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
	robot_status_t robot;
	robot.direction = direction;
	robot.position.x = x;
	robot.position.y = y;

	return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
	while (*commands) {
		
		switch (*commands++) {
			case 'R': robot->direction = (robot->direction + 1) % DIRECTION_MAX;
			break;
			case 'L': robot->direction = (robot->direction - 1) % DIRECTION_MAX; 
			break;
			case 'A': advance(robot); 
			break;
		}
	}
}

void advance(robot_status_t* robot)
{
	switch (robot->direction) {
		case DIRECTION_NORTH: robot->position.y++; break;
		case DIRECTION_EAST:  robot->position.x++; break;
		case DIRECTION_SOUTH: robot->position.y--; break;
		case DIRECTION_WEST:  robot->position.x--; break;
		default: break;
	}
}
