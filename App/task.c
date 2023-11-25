/*!
 * 
 * Author: Ice.Marek
 * IceNET Technology 2024
 * 
 */
#include "main.h"





void iceNET_Task(void)
{

	uint8_t transmitCharacter[1];

	UART_HandleTypeDef uart_console; // Declare the UART handle

	// Configure UART peripheral settings
	uart_console.Instance = USART1; // Specify which USART/UART peripheral to use (USART1 in this case)
	uart_console.Init.BaudRate = 9600; // Set the baud rate
	uart_console.Init.WordLength = UART_WORDLENGTH_8B; // Set data width to 8 bits
	uart_console.Init.StopBits = UART_STOPBITS_1; // Set one stop bit
	uart_console.Init.Parity = UART_PARITY_NONE; // Set no parity
	uart_console.Init.Mode = UART_MODE_TX_RX; // Set UART mode to both transmit and receive
	uart_console.Init.HwFlowCtl = UART_HWCONTROL_NONE; // Set no hardware flow control
	uart_console.Init.OverSampling = UART_OVERSAMPLING_16; // Set oversampling to 16

	// Initialize the UART peripheral with the configured settings
	HAL_UART_Init(&uart_console);

	transmitCharacter[0] = 48;

	while (1)
	{
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 1);
		HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, 0);


		HAL_UART_Transmit(&uart_console, transmitCharacter, 1, 100);

		transmitCharacter[0]++;

		HAL_Delay(100);
	}
}