/******************************************************************************
 * @file Led
 * @brief driver example a simple Led
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include "serial.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
service_t *service;

uint32_t serial_start_timeout = 0;

/*******************************************************************************
 * Function
 ******************************************************************************/

/******************************************************************************
 * @brief package init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Serial_Init(void)
{
    revision_t revision = {.major = 1, .minor = 0, .build = 0};

    // Create Led service
    service = Luos_CreateService(0, LUOS_LAST_TYPE, "serial_service", revision);
}
/******************************************************************************
 * @brief package loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Serial_Loop(void)
{
    if (Luos_GetSystick() - serial_start_timeout > 10000)
    {
        // Get the ID of our LED from the routing table
        int8_t id_encoder = RoutingTB_IDFromAlias("encoder_service");

        // Now send a message
        msg_t char_msg;
        char_msg.header.target      = id_encoder;
        char_msg.header.cmd         = IO_STATE;
        char_msg.header.target_mode = IDACK;
        char_msg.header.size        = sizeof(char);
        char_msg.data[0]            = 'c';
        Luos_SendMsg(service, &char_msg);

        serial_start_timeout = Luos_GetSystick();
    }
}
