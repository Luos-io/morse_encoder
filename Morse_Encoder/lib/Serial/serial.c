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
/*******************************************************************************
 * Variables
 ******************************************************************************/
service_t *service;
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
    service = Luos_CreateService(Serial_MsgHandler, SERIAL_TYPE, "serial_service", revision);
}
/******************************************************************************
 * @brief package loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Serial_Loop(void)
{
    uint8_t *word_buffer;
    uint8_t word_size;

    // get word size
    word_size = SerialCom_GetBufferSize();
    // get word table
    word_buffer = SerialCom_GetBufferData();
    // check if we have received a completed word
    if (word_size > 0)
    {
        // Get the ID of our encoder from the routing table
        int8_t id_encoder = RoutingTB_IDFromAlias("encoder_service");
        // Now create a message
        msg_t char_msg;
        char_msg.header.target      = id_encoder; // id of the encoder
        char_msg.header.cmd         = MORSE_CMD;  // specific custom command
        char_msg.header.target_mode = IDACK;
        char_msg.header.size        = sizeof(char) * word_size;
        // copy the word to the msg data
        memcpy(char_msg.data, &word_buffer[0], word_size * sizeof(uint8_t));
        // Send message to encoder
        Luos_SendMsg(service, &char_msg);
    }
}
/******************************************************************************
 * @brief Msg manager callback when a msg receive for the serial service
 * @param Service destination
 * @param Msg receive
 * @return None
 ******************************************************************************/
static void Serial_MsgHandler(service_t *service, msg_t *msg)
{
}