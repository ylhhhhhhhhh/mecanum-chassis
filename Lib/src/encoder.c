#include "encoder.h"
#include <stdint.h>

static uint32_t enc_value[4] = {0, 0, 0, 0};
static uint32_t enc_last_value[4] = {0, 0, 0, 0};
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;

void encoder_init(void) {
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);
}

static void encoder_update(void) {
  enc_last_value[ENCODERA] = enc_value[ENCODERA];
  enc_last_value[ENCODERB] = enc_value[ENCODERB];
  enc_last_value[ENCODERC] = enc_value[ENCODERC];
  enc_last_value[ENCODERD] = enc_value[ENCODERD];

  enc_value[ENCODERA] = __HAL_TIM_GET_COUNTER(&htim2);
  enc_value[ENCODERB] = __HAL_TIM_GET_COUNTER(&htim3);
  enc_value[ENCODERC] = __HAL_TIM_GET_COUNTER(&htim4);
  enc_value[ENCODERD] = __HAL_TIM_GET_COUNTER(&htim5);
}

static int32_t calc_delta(uint32_t now, uint32_t last) {
  uint16_t now16 = (uint16_t)now;
  uint16_t last16 = (uint16_t)last;
  return (int32_t)((int16_t)(now16 - last16));
}

void update_speed(Motor_speed *motorSpeed) {
  encoder_update();
  motorSpeed->va = calc_delta(enc_value[ENCODERA], enc_last_value[ENCODERA]);
  motorSpeed->vb = calc_delta(enc_value[ENCODERB], enc_last_value[ENCODERB]);
  motorSpeed->vc = calc_delta(enc_value[ENCODERC], enc_last_value[ENCODERC]);
  motorSpeed->vd = calc_delta(enc_value[ENCODERD], enc_last_value[ENCODERD]);
}
