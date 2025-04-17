#pragma once
#include "Button.h"

///
class PowerOffButton : public Button
{
public:
    ///
    PowerOffButton(uint8_t pin);

    ///
    virtual void OnPressed();

    ///
    virtual void OnHold();

    ///
    virtual void OnReleased();
};



