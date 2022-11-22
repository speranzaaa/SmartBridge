#ifndef BUTTON_IMPL
#define BUTTON_IMPL

#include "Button.h"

class ButtonImpl : public Button {
public:
    ButtonImpl(int pin);
    bool isPressed();

private:
    int pin;
};

#endif