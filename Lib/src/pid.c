#include "pid.h"
void PID_Init(PID *pid, float kp, float ki, float kd, float ki_limit,
              float output_limit, float target, float error_endurance,
              PID_MODE mode) {
  pid->kp = kp;
  pid->ki = ki;
  pid->kd = kd;
  pid->ki_limit = ki_limit;
  pid->output_limit = output_limit;
  pid->target = target;
  pid->error_endurance = error_endurance;
  pid->mode = mode;
  pid->error_sum = 0.0f;
  pid->last_error = 0.0f;
}

void PID_ChangeTarget(PID *pid, float target) { pid->target = target; }

float PID_Calculate(PID *pid, float current_value) {
  float output = 0.0f;
  float error = pid->target - current_value;
  float last_error = pid->last_error;
  pid->last_error = error;
  // 误差容忍
  if (error < pid->error_endurance && error > -pid->error_endurance) {
    error = 0;
  }

  if (pid->mode == P_M) {
    output = pid->kp * error;
  } else if (pid->mode == PI_M) {
    pid->error_sum += error;
    // 积分限幅
    if (pid->error_sum > pid->ki_limit) {
      pid->error_sum = pid->ki_limit;
    } else if (pid->error_sum < -pid->ki_limit) {
      pid->error_sum = -pid->ki_limit;
    }
    output = pid->kp * error + pid->ki * pid->error_sum;
  } else if (pid->mode == PID_M) {
    float derivative = (error - last_error);
    pid->error_sum += error;
    if (pid->error_sum > pid->ki_limit) {
      pid->error_sum = pid->ki_limit;
    } else if (pid->error_sum < -pid->ki_limit) {
      pid->error_sum = -pid->ki_limit;
    }
    output = pid->kp * error + pid->ki * pid->error_sum + pid->kd * derivative;
  } else if (pid->mode == PD_M) {
    float derivative = (error - last_error);
    output = pid->kp * error + pid->kd * derivative;
  }

  if (output > pid->output_limit) {
    output = pid->output_limit;
  } else if (output < -pid->output_limit) {
    output = -pid->output_limit;
  }
  return output;
}