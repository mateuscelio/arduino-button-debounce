#include "button_debounce.h"


void update_button_history(debounce_t *button) {
    button->history = (button->history << 1) | digitalRead(button->pin);
}

bool button_rose(debounce_t *button){
    if ((button->history & DEBOUNCE_MASK)== BUTTON_ROSE_PATTERN) {
        button->history = 0xff;
        return true;
    }
    return false;
};

bool button_fell(debounce_t *button){
    if ((button->history & DEBOUNCE_MASK)== BUTTON_FELL_PATTERN) {
        button->history = 0x0;
        return true;
    }
    return false;
};

bool button_pressed(debounce_t *button) {
    if (button->inverted) return button_fell(button);
    return button_rose(button);
};

bool button_released(debounce_t *button){
    if (button->inverted) return button_rose(button);
    return button_fell(button);
};

bool is_button_down(debounce_t *button) {
    if (button->inverted) return (button->history == BUTTON_UP_PATTERN);
    return (button->history == BUTTON_DOWN_PATTERN);
}

bool is_button_up(debounce_t *button) {
    if (button->inverted) return (button->history == BUTTON_DOWN_PATTERN);
    return (button->history == BUTTON_UP_PATTERN);
}