# arduino-button-debouncer
Simple arduino based debounce routine implementation from the article ["Embed With Elliot: Debounce Your Noisy Buttons, Part II"](https://hackaday.com/2015/12/10/embed-with-elliot-debounce-your-noisy-buttons-part-ii/).

# Use example

``` cpp
  #include <Arduino.h>
  #include "button_debounce.h"
  
  debounce_t button_1 = {18, true, 0x0};

  void setup() {
    pinMode(button_1.pin, INPUT_PULLUP);
  }
  
  void loop(){
  
    if (button_pressed(&button_1)) {
      // Do something when clicked
    }
    
    if (button_pressed(&button_1) || is_button_down(&button_1)) {
      // Do something when clicked and hold 
    }
  
    delay(10)
  }
  
```


