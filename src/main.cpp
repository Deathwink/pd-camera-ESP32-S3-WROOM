#include "Common.h"
#include <Arduino.h>
#include "PDCamera.h"
#include "PowerOffButton.h"

// Definizione dei pin per i pulsanti
#define BUTTON_PIN    0  // Pulsante per lo spegnimento

///
static PDCamera pdCamera;
static USBSerialHost& host = USBSerialHost::GetInstance();
static PowerOffButton offBtn(BUTTON_PIN);

// Funzione personalizzata per la gestione del log
void customLogPrint(const char* message) {
    Serial.println(message);
}

///
void setup()
{
    Serial.begin(115200);
    esp_log_level_set("*", ESP_LOG_NONE);

    // Inizializza il sistema di log personalizzato
    GLInitialize(customLogPrint);
    GLPrintln("== Begin pd-camera-freenove ==");

    // Configura la porta USB - Freenove ha 2 porte USB
    // Una porta verrà usata per l'alimentazione, l'altra per la comunicazione
    
    // Inizializza l'host USB e la fotocamera
    host.Initialize();
    pdCamera.Initialize();
    
    Serial.println("Sistema inizializzato");
    Serial.println("Collega la console Playdate...");
}


///
void loop()
{
    // Aggiorna lo stato dei pulsanti
    offBtn.Update();
    
    // Esegui il task principale della fotocamera
    pdCamera.AppTask();
}


