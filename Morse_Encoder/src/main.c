/******************************************************************************
 * @file main
 * @brief main file of the project
 * @author Yourself
 * @version 0.0.0
 ******************************************************************************/

#include "stm32f0xx_hal.h"
#include "luos.h"
#include "encoder.h"
#include "led.h"
#include "pipe.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/
void SystemClock_Config(void);

/******************************************************************************
 * @brief main function
 * @param None
 * @return None
 ******************************************************************************/
int main(void)
{
    HAL_Init();
    SystemClock_Config();

    // Init
    Luos_Init();
    Led_Init();
    Pipe_Init();
    Encoder_Init();

    while (1)
    {
        // Loop
        Luos_Loop();
        Led_Loop();
        Pipe_Loop();
        Encoder_Loop();
    }
}
/******************************************************************************
 * @brief System Clock Configuration
 * @param None
 * @return None
 ******************************************************************************/
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Initializes the CPU, AHB and APB busses clocks
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
    RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
    while (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
        ;

    /** Initializes the CPU, AHB and APB busses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    while (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
        ;
}