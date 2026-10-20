#ifndef MOTOR_H
#define MOTOR_H

#include "main.h"
#include <stdint.h>

#define MOTOR_TIM &htim1
#define MOTOR_A_CHANNEL TIM_CHANNEL_1
#define MOTOR_B_CHANNEL TIM_CHANNEL_2
#define MOTOR_C_CHANNEL TIM_CHANNEL_3
#define MOTOR_D_CHANNEL TIM_CHANNEL_4

typedef struct {
  float vx;
  float vy;
  float vz;
} Move_cmd;

#endif