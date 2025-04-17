#include "Button.h"

///
Button::Button(uint8_t pin, unsigned long holdThreshold)
    : m_pin(pin)
    , m_lastState(HIGH) // Assumiamo pull-up
    , m_currentState(HIGH)
    , m_pressTime(0)
    , m_holdThreshold(holdThreshold)
    , m_isHolding(false)
{
    pinMode(m_pin, INPUT_PULLUP);
}

///
Button::~Button()
{
}

///
void Button::Update()
{
    m_lastState = m_currentState;
    m_currentState = digitalRead(m_pin);
    
    // Controllo se il pulsante è stato premuto (transizione da HIGH a LOW con pull-up)
    if (m_lastState == HIGH && m_currentState == LOW) {
        m_pressTime = millis();
        OnPressed();
        m_isHolding = false;
    }
    // Controllo se il pulsante è tenuto premuto
    else if (m_currentState == LOW) {
        if (!m_isHolding && (millis() - m_pressTime) > m_holdThreshold) {
            OnHold();
            m_isHolding = true;
        }
    }
    // Controllo se il pulsante è stato rilasciato
    else if (m_lastState == LOW && m_currentState == HIGH) {
        OnReleased();
        m_isHolding = false;
    }
} 