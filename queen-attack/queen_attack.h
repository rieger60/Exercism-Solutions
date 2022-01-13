#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdint.h>
#include <stdbool.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;
typedef enum { OUT_OF_BOUNDS = 7 } out_of_bounds_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);
bool invalid_position(position_t queen_1, position_t queen_2);
bool diagonal_attack(position_t queen_1, position_t queen_2);

#endif
