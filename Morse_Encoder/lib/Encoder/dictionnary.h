/******************************************************************************
 * @file button
 * @brief driver example a simple button
 * @author Luos
 * @version 0.0.0
 ******************************************************************************/
#ifndef DICTIONNARY_H
#define DICTIONNARY_H

#include "encoder.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define LETTER_END 0xFFFFFFF1
#define WORD_END   0xFFFFFFF2

/*******************************************************************************
 * Variables
 ******************************************************************************/
MorseLetter end_word_letter = {
    .value = WORD_END};

MorseLetter end_letter = {
    .morse_element[0]       = {.state = false, .word_length = WORD_SPACE - SHORT},
    .morse_element[1].value = LETTER_END,
};

MorseLetter a_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4].value = LETTER_END,
};

MorseLetter b_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = SHORT},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter c_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = SHORT},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter d_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter e_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2].value = LETTER_END,
};

MorseLetter f_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = SHORT},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter g_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter h_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = SHORT},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter i_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4].value = LETTER_END,
};

MorseLetter j_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = LONG},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter k_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter l_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = SHORT},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter m_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4].value = LETTER_END,
};

MorseLetter n_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4].value = LETTER_END,
};

MorseLetter o_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter p_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = SHORT},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter q_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = LONG},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter r_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter s_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter t_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2].value = LETTER_END,
};

MorseLetter u_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter v_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = LONG},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter w_letter = {
    .morse_element[0]       = {.state = true, .word_length = SHORT},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6].value = LETTER_END,
};

MorseLetter x_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = LONG},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter y_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = SHORT},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = LONG},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = LONG},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

MorseLetter z_letter = {
    .morse_element[0]       = {.state = true, .word_length = LONG},
    .morse_element[1]       = {.state = false, .word_length = SHORT},
    .morse_element[2]       = {.state = true, .word_length = LONG},
    .morse_element[3]       = {.state = false, .word_length = SHORT},
    .morse_element[4]       = {.state = true, .word_length = SHORT},
    .morse_element[5]       = {.state = false, .word_length = SHORT},
    .morse_element[6]       = {.state = true, .word_length = SHORT},
    .morse_element[7]       = {.state = false, .word_length = SHORT},
    .morse_element[8].value = LETTER_END,
};

/*******************************************************************************
 * Function
 ******************************************************************************/

#endif /* DICTIONNARY_H */