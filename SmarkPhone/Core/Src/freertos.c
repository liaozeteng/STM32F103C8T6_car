/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Lcd_Driver.h"
#include "QDTFT_demo.h"
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
/* Definitions for LCDTask */
osThreadId_t LCDTaskHandle;
const osThreadAttr_t LCDTask_attributes = {
  .name = "LCDTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for KeyBordTask */
osThreadId_t KeyBordTaskHandle;
const osThreadAttr_t KeyBordTask_attributes = {
  .name = "KeyBordTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for GSMTask */
osThreadId_t GSMTaskHandle;
const osThreadAttr_t GSMTask_attributes = {
  .name = "GSMTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for FLASHTask */
osThreadId_t FLASHTaskHandle;
const osThreadAttr_t FLASHTask_attributes = {
  .name = "FLASHTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void LcdTask(void *argument);
void keybordTask(void *argument);
void gsmTask(void *argument);
void flashTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

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
  /* creation of LCDTask */
  LCDTaskHandle = osThreadNew(LcdTask, NULL, &LCDTask_attributes);

  /* creation of KeyBordTask */
  KeyBordTaskHandle = osThreadNew(keybordTask, NULL, &KeyBordTask_attributes);

  /* creation of GSMTask */
  GSMTaskHandle = osThreadNew(gsmTask, NULL, &GSMTask_attributes);

  /* creation of FLASHTask */
  FLASHTaskHandle = osThreadNew(flashTask, NULL, &FLASHTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_LcdTask */
/**
  * @brief  Function implementing the LCDTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_LcdTask */
void LcdTask(void *argument)
{
  /* USER CODE BEGIN LcdTask */
  /* Infinite loop */
	Lcd_Init();
	Redraw_Mainmenu();
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END LcdTask */
}

/* USER CODE BEGIN Header_keybordTask */
/**
* @brief Function implementing the KeyBordTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_keybordTask */
void keybordTask(void *argument)
{
  /* USER CODE BEGIN keybordTask */
  /* Infinite loop */
  for(;;)
  {
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_0);
    osDelay(100);
  }
  /* USER CODE END keybordTask */
}

/* USER CODE BEGIN Header_gsmTask */
/**
* @brief Function implementing the GSMTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_gsmTask */
void gsmTask(void *argument)
{
  /* USER CODE BEGIN gsmTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END gsmTask */
}

/* USER CODE BEGIN Header_flashTask */
/**
* @brief Function implementing the FLASHTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_flashTask */
void flashTask(void *argument)
{
  /* USER CODE BEGIN flashTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END flashTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
