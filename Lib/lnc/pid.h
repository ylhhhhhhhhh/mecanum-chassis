#ifndef PID_H
#define PID_H

typedef enum { P_M = 0, PI_M, PID_M, PD_M } PID_MODE;

typedef struct {
  float kp;
  float ki;
  float kd;
  float target;
  float ki_limit;
  float output_limit;
  float error_sum;
  float last_error;
  float error_endurance;
  PID_MODE mode;
} PID;

void PID_Init(PID *pid, float kp, float ki, float kd, float ki_limit,
              float output_limit, float target, float error_endurance,
              PID_MODE mode);
void PID_ChangeTarget(PID *pid, float target);
float PID_Calculate(PID *pid, float current_value);

#endif // PID_H
