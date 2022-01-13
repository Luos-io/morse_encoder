/******************************************************************************
 * @file button
 * @brief driver example a simple button
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#ifndef ENCODER_H
#define ENCODER_H

#include "luos.h"
#include "stdbool.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define SHORT_PERIOD 300

typedef enum WordLength
{
    SHORT      = SHORT_PERIOD,
    LONG       = 3 * SHORT_PERIOD,
    WORD_SPACE = 7 * SHORT_PERIOD,
} WordLength;

typedef struct MorseElement
{
    union
    {
        struct
        {
            uint16_t state;
            uint16_t word_length;
        };
        uint32_t value;
    };
} MorseElement;

typedef struct MorseLetter
{
    MorseElement morse_element[10];
} MorseLetter;

typedef struct MorseWord
{
    MorseLetter *morse_letter[3];
} MorseWord;

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/
void Encoder_Init(void);
void Encoder_Loop(void);

#endif /* ENCODER_H */
