#ifndef BUTTON_IMPL
#define BUTTON_IMPL

#include "button.h"

class ButtonImpl : public Button {
public:
    ButtonImpl(int pin);
    bool isPressed();

private:
    int pin;
};

#endif