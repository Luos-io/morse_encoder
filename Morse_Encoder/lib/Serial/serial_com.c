/******************************************************************************
 * @file serial_drv
 * @brief serial communication driver
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include "serial_com.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SERIAL_BUFFER_SIZE 10
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t serial_buffer[SERIAL_BUFFER_SIZE] = {0};
uint8_t data_counter                      = 0;
/*******************************************************************************
 * Function
 ******************************************************************************/
/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void SerialCom_Init(void)
{
    ///////////////////////////////
    // GPIO Serial Init
    ///////////////////////////////
    SERIAL_RX_CLK();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // RX
    GPIO_InitStruct.Pin       = SERIAL_RX_PIN;
    GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull      = GPIO_PULLUP;
    GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = SERIAL_RX_AF;
    HAL_GPIO_Init(SERIAL_RX_PORT, &GPIO_InitStruct);

    //////////////////////////////
    // USART SERIAL Init
    ///////////////////////////////
    SERIAL_COM_CLOCK_ENABLE();

    LL_USART_InitTypeDef USART_InitStruct;
    // Initialise USART
    LL_USART_Disable(SERIAL_COM);
    USART_InitStruct.BaudRate            = 1000000;
    USART_InitStruct.DataWidth           = LL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits            = LL_USART_STOPBITS_1;
    USART_InitStruct.Parity              = LL_USART_PARITY_NONE;
    USART_InitStruct.TransferDirection   = LL_USART_DIRECTION_RX;
    USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling        = LL_USART_OVERSAMPLING_16;
    while (LL_USART_Init(SERIAL_COM, &USART_InitStruct) != SUCCESS)
        ;
    LL_USART_Enable(SERIAL_COM);

    LL_USART_ClearFlag_IDLE(SERIAL_COM);
    LL_USART_EnableIT_IDLE(SERIAL_COM);

    HAL_NVIC_EnableIRQ(SERIAL_COM_IRQ);
    HAL_NVIC_SetPriority(SERIAL_COM_IRQ, 1, 1);
}

/******************************************************************************
 * @brief serial interrupt handler
 * @param None
 * @return None
 ******************************************************************************/
void SERIAL_COM_IRQHANDLER()
{
    static uint8_t i = 0;
    // check if we receive an IDLE on usart3
    if (LL_USART_IsActiveFlag_IDLE(SERIAL_COM) != RESET)
    {
        // clear the flag until the next reception
        LL_USART_ClearFlag_IDLE(SERIAL_COM);
        // keep in the characters buffer the last character received
        serial_buffer[i] = LL_USART_ReceiveData8(SERIAL_COM);
        // if the buffer has data 0 it has not received new data so we do nothing
        if (serial_buffer[i] == 0)
        {
            return;
        }
        // \r shows the end of the word
        if (serial_buffer[i] == '\r')
        {
            // keep the size of the world (\r included)
            data_counter = i + 1;
            i            = 0;
            return;
        }
        // next data will be stored in the next position
        i++;
    }
}
/******************************************************************************
 * @brief function that returns the size of the word
 * @param None
 * @return size of word or 0 if we have not a completed word
 ******************************************************************************/
uint8_t SerialCom_GetBufferSize(void)
{
    return data_counter;
}
/******************************************************************************
 * @brief function that returns a pointer to the word table
 * @param None
 * @return pointer to the word table
 ******************************************************************************/
uint8_t *SerialCom_GetBufferData(void)
{
    // we also need to reset the size to be ready for the next reception
    data_counter = 0;

    return &serial_buffer[0];
}