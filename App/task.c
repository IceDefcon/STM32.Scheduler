/*!
 * 
 * Author: Ice.Marek
 * IceNET Technology 2024
 * 
 */
#include "main.h"

void iceNET_Task(void)
{
	while (1)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);
		HAL_Delay(100);
	}
}