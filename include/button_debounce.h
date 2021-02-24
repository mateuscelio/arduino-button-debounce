#ifndef __BUTTON_DEBOUNCE__
#define __BUTTON_DEBOUNCE__

#include <Arduino.h>

#define DEBOUNCE_MASK 0b11000111
#define BUTTON_ROSE_PATTERN 0b00000111
#define BUTTON_FELL_PATTERN 0b11000000
#define BUTTON_DOWN_PATTERN 0xFF
#define BUTTON_UP_PATTERN 0x00

typedef struct {
	uint8_t pin;
    bool inverted; // Inverted means that the input operates in pull-up mode
	uint8_t history;
} debounce_t;


void update_button_history(debounce_t *button);

//Chekc if the button history changes following the pattern 0b00000111
bool button_rose(debounce_t *button);

//Chekc if the button history changes following the pattern 0b11000000
bool button_fell(debounce_t *button);

//Check if button is in down state
bool is_button_down(debounce_t *button);

//Ckech if button is in uṕ state
bool is_button_up(debounce_t *button);

//Check if button was pressed
bool button_pressed(debounce_t *button);

//Ckech if button was released
bool button_released(debounce_t *button);

#endif
