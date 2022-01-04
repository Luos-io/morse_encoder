/******************************************************************************
 * @file stm32f0xx_it
 * @brief Interrupt Service Routines.
 * @author Yourself
 * @version 0.0.0
 ******************************************************************************/
#include "stm32f0xx_hal.h"
#include "stm32f0xx_it.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */
/******************************************************************************/
void NMI_Handler(void)
{

}

void HardFault_Handler(void)
{
  while (1)
  {

  }
}

void SVC_Handler(void)
{

}

void PendSV_Handler(void)
{

}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/
void EXTI4_15_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);

}
