/******************************************************************************
 * @file app
 * @brief app that controls photosensor and solenoid
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#include <Arduino.h>
#include "app.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LED 32
/*******************************************************************************
 * Variables
 ******************************************************************************/
service_t *app;
uint8_t power_on = 0;
/*******************************************************************************
 * Function
 ******************************************************************************/
static void App_MsgHandler(service_t *service, msg_t *msg);
/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void App_Init(void)
{
    revision_t revision = {.major = 1, .minor = 0, .build = 0};
    pinMode(LED, OUTPUT);
    app = Luos_CreateService(App_MsgHandler, LUOS_LAST_TYPE, "app", revision);
    delay(100);
    Luos_Detect(app);
}
/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void App_Loop(void)
{
    if (Luos_IsNodeDetected())
    {
        if (power_on)
        {
            search_result_t result;
            RTFilter_Alias(RTFilter_Reset(&result), "solenoid");
            if (result.result_nbr > 0)
            {
                msg_t msg;
                msg.header.target      = result.result_table[0]->id;
                msg.header.target_mode = IDACK;
                msg.header.cmd         = GET_CMD;
                msg.header.size        = 1;
                msg.data[0]            = 1;
                Luos_SendMsg(app, &msg);
            }
            power_on = 0;
        }
    }
    else
    {
        pinMode(LED, OUTPUT);
        power_on = 0;
    }
}
/******************************************************************************
 * @brief Msg Handler call back when a msg receive for this service
 * @param Service destination
 * @param Msg receive
 * @return None
 ******************************************************************************/
static void App_MsgHandler(service_t *service, msg_t *msg)
{
    static uint8_t previous_state = 0;

    if (msg->header.cmd == IO_STATE)
    {
        if ((previous_state == 0) && (msg->data[0] != previous_state))
        {
            previous_state = 1;
            power_on       = 1;
        }
        else
        {
            previous_state = msg->data[0];
            power_on       = 0;
        }
        return;
    }
    else if (msg->header.cmd == END_DETECTION)
    {
        search_result_t result;
        RTFilter_Alias(RTFilter_Reset(&result), "sensor");
        if (result.result_nbr > 0)
        {
            msg_t pub_msg;
            pub_msg.header.target      = result.result_table[0]->id;
            pub_msg.header.target_mode = IDACK;
            time_luos_t time           = TimeOD_TimeFrom_s(0.005f);
            TimeOD_TimeToMsg(&time, &pub_msg);
            pub_msg.header.cmd = UPDATE_PUB;
            while (Luos_SendMsg(service, &pub_msg) != SUCCEED)
                ;
        }
    }
}
