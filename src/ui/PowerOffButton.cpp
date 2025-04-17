#include "PowerOffButton.h"
#include <Arduino.h>

///
PowerOffButton::PowerOffButton(uint8_t pin)
    : Button(pin)
{
}

///
void PowerOffButton::OnPressed()
{
    // In assenza del display, invia messaggio sulla seriale
    Serial.println("Pulsante premuto - tieni premuto per spegnere");
}

///
void PowerOffButton::OnHold()
{
    // Messaggio di conferma spegnimento
    Serial.println("Spegnimento in corso...");
    delay(1000); // Breve pausa prima di spegnere
    
    // Implementazione dello spegnimento
    // Su ESP32, possiamo utilizzare deep sleep
    esp_deep_sleep_start();
}

///
void PowerOffButton::OnReleased()
{
    // Semplice log quando il pulsante viene rilasciato
    Serial.println("Pulsante rilasciato");
}


