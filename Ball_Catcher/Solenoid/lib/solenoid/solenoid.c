/******************************************************************************
 * @file solenoid
 * @brief driver example a solenoid
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include <Arduino.h>
#include "solenoid.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SOLENOID_PIN 7
#define LED          32
/*******************************************************************************
 * Variables
 ******************************************************************************/
uint8_t val = LOW;
/*******************************************************************************
 * Function
 ******************************************************************************/
static void Solenoid_MsgHandler(service_t *service, msg_t *msg);
/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Solenoid_Init(void)
{
    revision_t revision = {.major = 1, .minor = 0, .build = 0};
    pinMode(LED, OUTPUT);
    pinMode(SOLENOID_PIN, OUTPUT);
    Luos_CreateService(Solenoid_MsgHandler, STATE_TYPE, "solenoid", revision);
}
/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Solenoid_Loop(void)
{
    if (Luos_IsNodeDetected())
    {
        if (val == HIGH)
        {
            delay(57);
            digitalWrite(SOLENOID_PIN, HIGH);
            delay(500);
            digitalWrite(SOLENOID_PIN, LOW);
            val = LOW;
        }
    }
    else
    {
        pinMode(SOLENOID_PIN, OUTPUT);
        pinMode(LED, OUTPUT);
        val = LOW;
    }
}
/******************************************************************************
 * @brief Msg Handler call back when a msg receive for this service
 * @param Service destination
 * @param Msg receive
 * @return None
 ******************************************************************************/
static void Solenoid_MsgHandler(service_t *service, msg_t *msg)
{
    static uint8_t i = 0;
    if (msg->header.cmd == GET_CMD)
    {
        if (msg->data[0] == 1)
        {
            i = !i;
            digitalWrite(LED, i);
            val = HIGH;
        }
    }
}
