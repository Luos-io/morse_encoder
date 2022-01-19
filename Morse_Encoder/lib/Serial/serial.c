/******************************************************************************
 * @file Serial
 * @brief driver example of serial communication
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include "serial.h"
#include "serial_com.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
typedef enum
{
    ENCODER_TYPE = LUOS_LAST_TYPE,
    SERIAL_TYPE,
} custom_type_t;
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*******************************************************************************
 * Function
 ******************************************************************************/
static void Serial_MsgHandler(service_t *service, msg_t *msg);
/******************************************************************************
 * @brief package init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Serial_Init(void)
{
    revision_t revision = {.major = 1, .minor = 0, .build = 0};
    // Initialize Serial Com Driver
    SerialCom_Init();
    // Create Serial service
    Luos_CreateService(Serial_MsgHandler, SERIAL_TYPE, "serial_service", revision);
}
/******************************************************************************
 * @brief package loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Serial_Loop(void)
{
}
/******************************************************************************
 * @brief Msg manager callback when a msg receive for the serial service
 * @param Service destination
 * @param Msg receive
 * @return None
 ******************************************************************************/
static void Serial_MsgHandler(service_t *service, msg_t *msg)
{

    if (msg->header.cmd == GET_CMD)
    {
        uint8_t *word_buffer;
        uint8_t word_size;

        // get word size
        word_size = SerialCom_GetBufferSize();
        // check if we have received a completed word
        if (word_size > 0)
        {
            // get word table
            word_buffer = SerialCom_GetBufferData();
            // Now create a message
            msg_t char_msg;
            char_msg.header.target      = msg->header.source; // id of the service that demands updates
            char_msg.header.cmd         = SET_CMD;            // specific command
            char_msg.header.target_mode = IDACK;
            char_msg.header.size        = sizeof(char) * word_size;
            // copy the word to the msg data
            memcpy(char_msg.data, &word_buffer[0], word_size * sizeof(uint8_t));
            // Send message to encoder
            Luos_SendMsg(service, &char_msg);
        }
    }
}