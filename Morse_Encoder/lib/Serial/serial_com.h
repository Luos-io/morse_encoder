/******************************************************************************
 * @file serial_com
 * @brief serial communication driver
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#ifndef SERIAL_COM_H
#define SERIAL_COM_H

#include "stm32f0xx_hal.h"
#include "stm32f0xx_ll_usart.h"
#include "stm32f0xx_ll_gpio.h"
#include "stm32f0xx_ll_exti.h"
#include "stm32f0xx_ll_dma.h"
#include "stm32f0xx_ll_system.h"
#include "stm32f0xx_hal.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SERIAL_RX_CLK() __HAL_RCC_GPIOA_CLK_ENABLE()
#define SERIAL_RX_PIN   GPIO_PIN_3
#define SERIAL_RX_PORT  GPIOA
#define SERIAL_RX_AF    GPIO_AF1_USART2

#define SERIAL_COM_CLOCK_ENABLE() __HAL_RCC_USART2_CLK_ENABLE()
#define SERIAL_COM                USART2
#define SERIAL_COM_IRQ            USART2_IRQn
#define SERIAL_COM_IRQHANDLER()   USART2_IRQHandler()

#define SERIAL_BUFFER_SIZE 10
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/
void SerialCom_Init(void);
uint8_t SerialCom_GetBufferSize(void);
uint8_t *SerialCom_GetBufferData(void);

#endif /* SERIAL_COM_H */