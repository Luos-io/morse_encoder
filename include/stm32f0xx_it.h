/******************************************************************************
 * @file Morse_Encoder_IT
 * @brief Interrupt Service Routines.
 * @author Yourself
 * @version 0.0.0
 ******************************************************************************/
#ifndef __MORSE_ENCODER_IT_H
#define __MORSE_ENCODER_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/
void NMI_Handler(void);
void HardFault_Handler(void);
void SVC_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void EXTI4_15_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __MORSE_ENCODER_IT_H */