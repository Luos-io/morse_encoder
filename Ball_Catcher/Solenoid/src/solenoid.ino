#include <Arduino.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include <luos.h>
#include "solenoid.h"
#include "app.h"
#ifdef __cplusplus
}
#endif

/******************************************************************************
 * @brief Setup ardiuno
 * @param None
 * @return None
 ******************************************************************************/
void setup()
{
    Luos_Init();
    Solenoid_Init();
    App_Init();
}
/******************************************************************************
 * @brief Loop Arduino
 * @param None
 * @return None
 ******************************************************************************/
void loop()
{
    Luos_Loop();
    Solenoid_Loop();
    App_Loop();
}
