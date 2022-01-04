/******************************************************************************
 * @file main
 * @brief main file of the project
 * @author Yourself
 * @version 0.0.0
 ******************************************************************************/

#include "stm32f0xx_hal.h"
#include "luos.h"

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
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    static volatile uint32_t i = 0;

    HAL_Init();
    SystemClock_Config();

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // Init
    Luos_Init();
    while (1)
    {
        // Loop

        Luos_Loop();
        if (i > 10000)
        {
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
            i = 0;
        }
        else
        {
            i++;
        }
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