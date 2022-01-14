/******************************************************************************
 * @file button
 * @brief driver example a simple button
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/

#include "encoder.h"
#include "dictionnary.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
service_t *service;

// morse variables
MorseLetter *letter_to_play;

MorseWord sos_table = {
    .morse_letter[0] = &s_letter,
    .morse_letter[1] = &o_letter,
    .morse_letter[2] = &s_letter,
    .morse_letter[3] = &end_letter,
    .morse_letter[4] = &end_word_letter,
};

uint8_t morse_state          = false;
WordLength morse_period      = 0;
uint32_t morse_start_timeout = 0;
uint16_t element_index       = 0;
uint16_t letter_index        = 0;
bool end_of_word             = false;
bool end_of_letter           = true;

bool serial_detected = false;
/*******************************************************************************
 * Function
 ******************************************************************************/
void Encoder_SendMorse(bool state);
void Encoder_MsgHandler(service_t *service, msg_t *msg);
void Encoder_PlayWord(MorseWord *morse_word);
void Encoder_PlayLetter(MorseLetter *letter);

/******************************************************************************
 * @brief init must be call in project init
 * @param None
 * @return None
 ******************************************************************************/
void Encoder_Init(void)
{
    // service initialization
    revision_t revision = {.major = 1, .minor = 0, .build = 0};
    // Service creation following state profile
    service = Luos_CreateService(Encoder_MsgHandler, LUOS_LAST_TYPE, "encoder_service", revision);
    // Detect all services of your network and create a routing_table
    RoutingTB_DetectServices(service);

    // initialize variables
    morse_state         = false;
    morse_period        = 0;
    morse_start_timeout = 0;
    element_index       = 0;
    letter_index        = 0;
    end_of_letter       = true;
    end_of_word         = false;
}

/******************************************************************************
 * @brief loop must be call in project loop
 * @param None
 * @return None
 ******************************************************************************/
void Encoder_Loop(void)
{
    if (Luos_IsNodeDetected())
    {
        if (RoutingTB_IDFromAlias("serial_service"))
        {
            serial_detected = true;
        }
        else
        {
            serial_detected = false;
        }

        if (!serial_detected)
        {
            Encoder_PlayLetter(letter_to_play);
        }
        else
        {
            end_of_word = false;
            Encoder_PlayWord(&sos_table);
        }
    }
}

/******************************************************************************
 * @brief send a luos message to the led
 * @param State to send to the led
 * @return None
 ******************************************************************************/
void Encoder_SendMorse(bool state)
{
    // Get the ID of our LED from the routing table
    int8_t id_led = RoutingTB_IDFromAlias("led_service");

    // Now send a message
    msg_t led_msg;
    led_msg.header.target      = id_led;
    led_msg.header.cmd         = IO_STATE;
    led_msg.header.target_mode = IDACK;
    led_msg.header.size        = sizeof(char);
    led_msg.data[0]            = state;
    Luos_SendMsg(service, &led_msg);
}

/******************************************************************************
 * @brief manage messages send to the service
 * @param Service which send the message
 * @param msg which send the message
 * @return None
 ******************************************************************************/
void Encoder_MsgHandler(service_t *service, msg_t *msg)
{
    char received_letter = (char)(msg->data[0]);
    switch (received_letter)
    {
        case 'a':
            letter_to_play = &a_letter;
            end_of_letter  = false;
            break;
        case 'b':
            letter_to_play = &b_letter;
            end_of_letter  = false;
            break;
        case 'c':
            letter_to_play = &c_letter;
            end_of_letter  = false;
            break;
        case 'd':
            letter_to_play = &d_letter;
            end_of_letter  = false;
            break;
        case 'e':
            letter_to_play = &e_letter;
            end_of_letter  = false;
            break;
        case 'f':
            letter_to_play = &f_letter;
            end_of_letter  = false;
            break;
        case 'g':
            letter_to_play = &g_letter;
            end_of_letter  = false;
            break;
        case 'h':
            letter_to_play = &h_letter;
            end_of_letter  = false;
            break;
        case 'i':
            letter_to_play = &i_letter;
            end_of_letter  = false;
            break;
        case 'j':
            letter_to_play = &j_letter;
            end_of_letter  = false;
            break;
        case 'k':
            letter_to_play = &k_letter;
            end_of_letter  = false;
            break;
        case 'l':
            letter_to_play = &l_letter;
            end_of_letter  = false;
            break;
        case 'm':
            letter_to_play = &m_letter;
            end_of_letter  = false;
            break;
        case 'n':
            letter_to_play = &n_letter;
            end_of_letter  = false;
            break;
        case 'o':
            letter_to_play = &o_letter;
            end_of_letter  = false;
            break;
        case 'p':
            letter_to_play = &p_letter;
            end_of_letter  = false;
            break;
        case 'q':
            letter_to_play = &q_letter;
            end_of_letter  = false;
            break;
        case 'r':
            letter_to_play = &r_letter;
            end_of_letter  = false;
            break;
        case 's':
            letter_to_play = &s_letter;
            end_of_letter  = false;
            break;
        case 't':
            letter_to_play = &t_letter;
            end_of_letter  = false;
            break;
        case 'u':
            letter_to_play = &u_letter;
            end_of_letter  = false;
            break;
        case 'v':
            letter_to_play = &v_letter;
            end_of_letter  = false;
            break;
        case 'w':
            letter_to_play = &w_letter;
            end_of_letter  = false;
            break;
        case 'x':
            letter_to_play = &x_letter;
            end_of_letter  = false;
            break;
        case 'y':
            letter_to_play = &y_letter;
            end_of_letter  = false;
            break;
        case 'z':
            letter_to_play = &z_letter;
            end_of_letter  = false;
            break;
        default:
            end_of_letter = true;
            break;
    }
}

/******************************************************************************
 * @brief Play S.O.S sequence
 * @param None
 * @return None
 ******************************************************************************/
void Encoder_PlayWord(MorseWord *morse_word)
{
    // send a word sequence
    if ((morse_word->morse_letter[letter_index]->value != WORD_END) & !end_of_word)
    {
        Encoder_PlayLetter(morse_word->morse_letter[letter_index]);

        if (end_of_letter)
        {
            end_of_letter = false;
            letter_index += 1;
        }
    }
    else
    {
        // end of word
        letter_index = 0;
        end_of_word  = true;
    }
}

/******************************************************************************
 * @brief Play a letter sequence
 * @param None
 * @return None
 ******************************************************************************/
void Encoder_PlayLetter(MorseLetter *letter)
{
    // for each element in a letter
    if ((letter->morse_element[element_index].value != LETTER_END) & !end_of_letter)
    {
        if (Luos_GetSystick() - morse_start_timeout > morse_period)
        {
            morse_state  = letter->morse_element[element_index].state;
            morse_period = letter->morse_element[element_index].word_length;
            // send new led state
            Encoder_SendMorse(morse_state);
            // wait for the time period
            morse_start_timeout = Luos_GetSystick();
            // go to the next element
            element_index += 1;
        }
    }
    else
    {
        // reset element index and go to the next letter
        element_index = 0;
        end_of_letter = true;
    }
}