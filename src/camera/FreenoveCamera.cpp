#include "FreenoveCamera.h"
#include <Arduino.h> // Per la funzione constrain

///
FreenoveCamera::FreenoveCamera()
    : m_sensor(nullptr)
{
}

///
FreenoveCamera::~FreenoveCamera()
{
    esp_camera_deinit();
}

///
bool FreenoveCamera::Initialize()
{
    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    config.pin_d0 = CAMERA_PIN_D0;
    config.pin_d1 = CAMERA_PIN_D1;
    config.pin_d2 = CAMERA_PIN_D2;
    config.pin_d3 = CAMERA_PIN_D3;
    config.pin_d4 = CAMERA_PIN_D4;
    config.pin_d5 = CAMERA_PIN_D5;
    config.pin_d6 = CAMERA_PIN_D6;
    config.pin_d7 = CAMERA_PIN_D7;
    config.pin_xclk = CAMERA_PIN_XCLK;
    config.pin_pclk = CAMERA_PIN_PCLK;
    config.pin_vsync = CAMERA_PIN_VSYNC;
    config.pin_href = CAMERA_PIN_HREF;
    config.pin_sccb_sda = CAMERA_PIN_SIOD;
    config.pin_sccb_scl = CAMERA_PIN_SIOC;
    config.pin_pwdn = CAMERA_PIN_PWDN;
    config.pin_reset = CAMERA_PIN_RESET;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_GRAYSCALE;
    config.frame_size = FRAMESIZE_QVGA;
    config.jpeg_quality = 10;
    config.fb_count = 2;
    config.grab_mode = CAMERA_GRAB_WHEN_EMPTY;

    // Inizializza la fotocamera
    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
        Serial.printf("Errore inizializzazione fotocamera: 0x%x\n", err);
        return false;
    }

    m_sensor = esp_camera_sensor_get();
    if (!m_sensor) {
        Serial.println("Impossibile ottenere il sensore della fotocamera");
        return false;
    }

    // Imposta alcuni parametri della fotocamera
    m_sensor->set_brightness(m_sensor, 0);     // -2 to 2
    m_sensor->set_contrast(m_sensor, 0);       // -2 to 2
    m_sensor->set_saturation(m_sensor, 0);     // -2 to 2
    m_sensor->set_sharpness(m_sensor, 0);      // -2 to 2
    m_sensor->set_denoise(m_sensor, 1);
    m_sensor->set_hmirror(m_sensor, 0);        // 0 = disable, 1 = enable
    m_sensor->set_vflip(m_sensor, 0);          // 0 = disable, 1 = enable
    m_sensor->set_raw_gma(m_sensor, 1);        // 0 = disable, 1 = enable
    m_sensor->set_dcw(m_sensor, 1);            // 0 = disable, 1 = enable
    
    Serial.println("Fotocamera Freenove inizializzata");
    return true;
}

///
void FreenoveCamera::SetContrast(int contrast)
{
    if (m_sensor) {
        // Limita il valore tra -2 e 2
        int constrainedValue = (contrast < -2) ? -2 : ((contrast > 2) ? 2 : contrast);
        m_sensor->set_contrast(m_sensor, constrainedValue);
    }
}

///
void FreenoveCamera::SetBrightness(int brightness)
{
    if (m_sensor) {
        // Limita il valore tra -2 e 2
        int constrainedValue = (brightness < -2) ? -2 : ((brightness > 2) ? 2 : brightness);
        m_sensor->set_brightness(m_sensor, constrainedValue);
    }
}

///
void FreenoveCamera::SetMirror(int mirror)
{
    if (m_sensor) {
        m_sensor->set_hmirror(m_sensor, mirror ? 1 : 0);
    }
}

///
void FreenoveCamera::Capture(DataBuffer* data)
{
    if (!data) return;

    camera_fb_t* fb = esp_camera_fb_get();
    if (!fb) {
        Serial.println("Impossibile acquisire immagine dalla fotocamera");
        return;
    }

    // Copia i dati dell'immagine nel buffer
    if (fb->format == PIXFORMAT_GRAYSCALE && fb->len == CAMERA_DATA_SIZE_W * CAMERA_DATA_SIZE_H) {
        memcpy(data->GetBuffer(), fb->buf, fb->len);
        // In DataBuffer non abbiamo SetLength, ma possiamo assumere che il buffer abbia la dimensione
        // corretta visto che viene creato con la dimensione precisa in PDCameraTask
    } else {
        Serial.printf("Formato immagine non supportato: %d, dimensione: %d\n", fb->format, fb->len);
    }

    esp_camera_fb_return(fb);
} 