#pragma once
#include <Arduino.h>

///
class Button {
protected:
    uint8_t m_pin;
    bool m_lastState;
    bool m_currentState;
    unsigned long m_pressTime;
    unsigned long m_holdThreshold;
    bool m_isHolding;

public:
    ///
    Button(uint8_t pin, unsigned long holdThreshold = 2000);
    
    ///
    virtual ~Button();

    ///
    void Update();

    ///
    virtual void OnPressed() = 0;

    ///
    virtual void OnHold() = 0;

    ///
    virtual void OnReleased() = 0;
}; 