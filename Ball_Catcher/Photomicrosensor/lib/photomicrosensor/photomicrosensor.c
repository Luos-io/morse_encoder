/******************************************************************************
 * @file photomicrosensor
 * @brief driver example a photomicrosensor
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include <Arduino.h>
#include "photomicrosensor.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define PHOTOIN_PIN 7
#define LED         32
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t val = LOW;
/*******************************************************************************
 * Function
 ******************************************************************************/
static void PhotoSensor_MsgHandler(service_t *service, msg_t *msg);
/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void PhotoSensor_Init(void)
{
    revision_t revision = {.major = 1, .minor = 0, .build = 0};
    pinMode(PHOTOIN_PIN, INPUT_PULLUP);
    pinMode(LED, OUTPUT);
    Luos_CreateService(PhotoSensor_MsgHandler, STATE_TYPE, "photo_sensor", revision);
}
/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void PhotoSensor_Loop(void)
{
    if (Luos_IsNodeDetected())
    {
        val = (bool)digitalRead(PHOTOIN_PIN);
    }
    else
    {
        pinMode(PHOTOIN_PIN, INPUT_PULLUP);
        val = 0;
    }
}
/******************************************************************************
 * @brief Msg Handler call back when a msg receive for this service
 * @param Service destination
 * @param Msg receive
 * @return None
 ******************************************************************************/
static void PhotoSensor_MsgHandler(service_t *service, msg_t *msg)
{
    if (msg->header.cmd == GET_CMD)
    {
        // fill the message infos
        msg_t pub_msg;
        pub_msg.header.cmd         = IO_STATE;
        pub_msg.header.target_mode = ID;
        pub_msg.header.target      = msg->header.source;
        pub_msg.header.size        = 1;
        pub_msg.data[0]            = val;
        Luos_SendMsg(service, &pub_msg);
        return;
    }
}
