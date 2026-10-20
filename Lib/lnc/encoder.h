#ifndef ENCODER_H
#define ENCODER_H

#include "main.h"

typedef enum { ENCODERA = 0, ENCODERB, ENCODERC, ENCODERD } Encoder_TypeDef;

typedef struct {
  int32_t va;
  int32_t vb;
  int32_t vc;
  int32_t vd;
} Motor_speed;

void encoder_init(void);
void update_speed(Motor_speed *motorSpeed);

#endif
