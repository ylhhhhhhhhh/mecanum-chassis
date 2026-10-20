/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2026 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "main.h"
#include "task.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "encoder.h"
#include "font.h"
#include "oled.h"
#include "tim.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId show_taskHandle;
osThreadId motor_taskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const *argument);
void StartTask02(void const *argument);
void Motor_task(void const *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize);

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer,
                                   StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize) {
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of show_task */
  osThreadDef(show_task, StartTask02, osPriorityIdle, 0, 128);
  show_taskHandle = osThreadCreate(osThread(show_task), NULL);

  /* definition and creation of motor_task */
  osThreadDef(motor_task, Motor_task, osPriorityIdle, 0, 128);
  motor_taskHandle = osThreadCreate(osThread(motor_task), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */
}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const *argument) {
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for (;;) {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
 * @brief Function implementing the show_task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartTask02 */
void StartTask02(void const *argument) {
  /* USER CODE BEGIN StartTask02 */
  /* Infinite loop */
  for (;;) {
    // OLED_NewFrame();
    // OLED_PrintString(1, 1, "hello", &font16x16, OLED_COLOR_NORMAL);
    // OLED_ShowFrame();
    osDelay(1);
  }
  /* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_Motor_task */
/**
 * @brief Function implementing the motor_task thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_Motor_task */
void Motor_task(void const *argument) {
  /* USER CODE BEGIN Motor_task */
  encoder_init();
  Motor_speed ms;
  // pwm电机测试
  //  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
  //  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
  //  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_7, GPIO_PIN_SET);
  //  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_8, GPIO_PIN_RESET);
  //  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);
  //  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
  //  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
  //  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_10, GPIO_PIN_RESET);
  //  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  //  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  //  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  //  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
  //  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 4200);
  //  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 4200);
  //  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 4200);
  //  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 4200);
  /* Infinite loop */
  for (;;) {
    update_speed(&ms);
    OLED_NewFrame();
    OLED_PrintAt(0, 0, &afont16x8, OLED_COLOR_NORMAL, "A:%ld", ms.va);
    OLED_PrintAt(0, 16, &afont16x8, OLED_COLOR_NORMAL, "B:%ld", ms.vb);
    OLED_PrintAt(0, 32, &afont16x8, OLED_COLOR_NORMAL, "C:%ld", ms.vc);
    OLED_PrintAt(0, 48, &afont16x8, OLED_COLOR_NORMAL, "D:%ld", ms.vd);
    OLED_ShowFrame();
    osDelay(10);
  }
  /* USER CODE END Motor_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */
