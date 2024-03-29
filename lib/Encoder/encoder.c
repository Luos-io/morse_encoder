/******************************************************************************
 * @file encoder
 * @brief encoder app
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/

#include "encoder.h"
#include "dictionnary.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define limit_character '\r'

typedef enum
{
    ENCODER_TYPE = LUOS_LAST_TYPE,
} custom_type_t;
/*******************************************************************************
 * Variables
 ******************************************************************************/
service_t *service;

// morse variables
MorseWord receive_word;

MorseWord sos_table = {
    .morse_letter[0] = &s_letter,
    .morse_letter[1] = &o_letter,
    .morse_letter[2] = &s_letter,
    .morse_letter[3] = &end_letter,
    .morse_letter[4] = &end_word_marker,
};

uint8_t morse_state = false;
WordLength morse_period = 0;
uint32_t morse_start_timeout = 0;
uint16_t element_index = 0;
uint16_t letter_index = 0;
bool end_of_word = false;
bool end_of_letter = true;

bool serial_detected = false;
uint8_t output_id = 0;
/*******************************************************************************
 * Function
 ******************************************************************************/
void Encoder_SendMorse(bool state);
void Encoder_MsgHandler(service_t *service, msg_t *msg);
void Encoder_PlayWord(MorseWord *morse_word);
void Encoder_PlayLetter(MorseLetter *letter);
MorseLetter *Encoder_DecodeLetter(char letter);

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
    service = Luos_CreateService(Encoder_MsgHandler, ENCODER_TYPE, "encoder_service", revision);
    // Detect all services of your network and create a routing_table
    Luos_Detect(service);

    // initialize variables
    morse_state = false;
    morse_period = 0;
    morse_start_timeout = 0;
    element_index = 0;
    letter_index = 0;
    end_of_letter = true;
    end_of_word = true;
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
        if (serial_detected)
        {
            Encoder_PlayWord(&receive_word);
        }
        else
        {
            end_of_word = false;
            Encoder_PlayWord(&sos_table);
        }
    }
}

/******************************************************************************
 * @brief manage messages send to the service
 * @param Service which send the message
 * @param msg which send the message
 * @return None
 ******************************************************************************/
void Encoder_MsgHandler(service_t *service, msg_t *msg)
{
    uint16_t index = 0;

    if (msg->header.cmd == SET_CMD)
    {
        while (msg->data[index] != '\r')
        {
            receive_word.morse_letter[index] = Encoder_DecodeLetter(msg->data[index]);
            index += 1;
        }
        receive_word.morse_letter[index] = &end_letter;
        receive_word.morse_letter[index + 1] = &end_word_marker;

        end_of_word = false;
        end_of_letter = false;
    }
    if (msg->header.cmd == END_DETECTION)
    {
        search_result_t result;
        RTFilter_Type(RTFilter_Reset(&result), STATE_TYPE);
        output_id = result.result_table[0]->id;
        RTFilter_Type(RTFilter_Reset(&result), PIPE_TYPE);
        if (result.result_nbr > 0)
        {
            time_luos_t update_time = 0.01;
            msg_t update_msg;
            update_msg.header.target = result.result_table[0]->id;
            update_msg.header.target_mode = IDACK;
            TimeOD_TimeToMsg(&update_time, &update_msg);
            update_msg.header.cmd = UPDATE_PUB;
            Luos_SendMsg(service, &update_msg);
            serial_detected = true;
            return;
        }
        serial_detected = false;
    }
}

/******************************************************************************
 * @brief decode received letters
 * @param letter to decode
 * @return MorseLetter pointer
 ******************************************************************************/
MorseLetter *Encoder_DecodeLetter(char letter)
{
    switch (letter)
    {
    case 'a':
        return &a_letter;
    case 'b':
        return &b_letter;
    case 'c':
        return &c_letter;
    case 'd':
        return &d_letter;
    case 'e':
        return &e_letter;
    case 'f':
        return &f_letter;
    case 'g':
        return &g_letter;
    case 'h':
        return &h_letter;
    case 'i':
        return &i_letter;
    case 'j':
        return &j_letter;
    case 'k':
        return &k_letter;
    case 'l':
        return &l_letter;
    case 'm':
        return &m_letter;
    case 'n':
        return &n_letter;
    case 'o':
        return &o_letter;
    case 'p':
        return &p_letter;
    case 'q':
        return &q_letter;
    case 'r':
        return &r_letter;
    case 's':
        return &s_letter;
    case 't':
        return &t_letter;
    case 'u':
        return &u_letter;
    case 'v':
        return &v_letter;
    case 'w':
        return &w_letter;
    case 'x':
        return &x_letter;
    case 'y':
        return &y_letter;
    case 'z':
        return &z_letter;
    default:
        return 0;
    }
}

/******************************************************************************
 * @brief Play a word
 * @param None
 * @return None
 ******************************************************************************/
void Encoder_PlayWord(MorseWord *morse_word)
{
    // send a word sequence
    if ((morse_word->morse_letter[letter_index]->value != WORD_END) && !end_of_word)
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
        end_of_word = true;
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
    if ((letter->morse_element[element_index].value != LETTER_END) && !end_of_letter)
    {
        if (Luos_GetSystick() - morse_start_timeout > morse_period)
        {
            morse_state = letter->morse_element[element_index].state;
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

/******************************************************************************
 * @brief send a luos message to the led
 * @param State to send to the led
 * @return None
 ******************************************************************************/
void Encoder_SendMorse(bool state)
{
    // Now send a message
    if (output_id > 0)
    {
        msg_t led_msg;
        led_msg.header.target = output_id;
        led_msg.header.cmd = IO_STATE;
        led_msg.header.target_mode = IDACK;
        led_msg.header.size = sizeof(char);
        led_msg.data[0] = state;
        Luos_SendMsg(service, &led_msg);
    }
}