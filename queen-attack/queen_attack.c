#include "queen_attack.h"

attack_status_t can_attack(position_t queen_1, position_t queen_2)
{

	if (invalid_position(queen_1, queen_2)) {
		return INVALID_POSITION;
	}

	if (queen_1.row == queen_2.row)
		return CAN_ATTACK;

	if (queen_1.column == queen_2.column)
		return CAN_ATTACK;

	if (diagonal_attack(queen_1, queen_2))
		return CAN_ATTACK;

	return CAN_NOT_ATTACK;
}

bool invalid_position(position_t queen_1, position_t queen_2)
{
	if (queen_1.row == queen_2.row &&
		queen_1.column == queen_2.column)
		return true;

	if (queen_1.row > OUT_OF_BOUNDS || queen_1.column > OUT_OF_BOUNDS)
		return true;

	if (queen_2.row > OUT_OF_BOUNDS || queen_2.column > OUT_OF_BOUNDS)
		return true;

	return false;
}

bool diagonal_attack(position_t queen_1, position_t queen_2)
{
	uint8_t row_abs = (queen_1.row > queen_2.row) ?
						queen_1.row - queen_2.row : 
						queen_2.row - queen_1.row;

	uint8_t col_abs = (queen_1.column > queen_2.column) ?
						queen_1.column - queen_2.column :
						queen_2.column - queen_1.column;

	if (row_abs == col_abs)
		return true;

	return false;
}