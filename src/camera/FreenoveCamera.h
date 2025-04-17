#pragma once
#include "Common.h"
#include "CameraIF.h"
#include <esp_camera.h>

///
class FreenoveCamera
    : public CameraIF
{
private:
    ///
    sensor_t* m_sensor;

public:
    ///
    FreenoveCamera();

    ///
    ~FreenoveCamera();

    /*
        CameraIF
    */
    ///
    virtual bool Initialize();

    ///
    virtual void SetContrast(int contrast);

    ///
    virtual void SetBrightness(int brightness);

    ///
    virtual void SetMirror(int mirror);

    ///
    virtual void Capture(DataBuffer* data);
}; 