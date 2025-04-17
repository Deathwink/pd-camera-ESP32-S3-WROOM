#pragma once


#define ENABLE_GROVE_LOG


#include <stdint.h>
#include <stddef.h>
#include <memory.h>
#include <vector>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Include headers for Freenove ESP32-S3-WROOM CAM
#ifdef FREENOVE_ESP32S3_WROOM
#include <Arduino.h>
#endif

#include "GroveLog.h"

// Definizione della dimensione della fotocamera
#define CAMERA_DATA_SIZE_W 320
#define CAMERA_DATA_SIZE_H 240

// Definizione dei PIN per Freenove ESP32-S3-WROOM CAM
#ifdef FREENOVE_ESP32S3_WROOM
// Pin per la fotocamera OV2640
#define CAMERA_PIN_PWDN     -1
#define CAMERA_PIN_RESET    -1
#define CAMERA_PIN_XCLK     15
#define CAMERA_PIN_SIOD     4
#define CAMERA_PIN_SIOC     5
#define CAMERA_PIN_D7       16
#define CAMERA_PIN_D6       17
#define CAMERA_PIN_D5       18
#define CAMERA_PIN_D4       19
#define CAMERA_PIN_D3       21
#define CAMERA_PIN_D2       22
#define CAMERA_PIN_D1       23
#define CAMERA_PIN_D0       25
#define CAMERA_PIN_VSYNC    32
#define CAMERA_PIN_HREF     33
#define CAMERA_PIN_PCLK     34
#endif





