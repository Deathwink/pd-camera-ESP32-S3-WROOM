# PD-Camera for Freenove ESP32-S3-WROOM CAM

This project adapts the [PD-Camera project](https://github.com/t0mg/pd-camera) to work with the Freenove ESP32-S3-WROOM CAM board, allowing it to serve as a camera accessory for the Playdate console.

> PD-Camera is an unofficial, experimental accessory for [Panic Inc.](https://panic.com/)'s [Playdate](https://play.date) handheld console, which as the name hopefully suggests allows the device to record pictures as well as animated gifs, in whopping 1-bit color and QVGA (320x240) resolution. Kind of similar to the [1998 accessory for that other monochrome handheld device](https://en.wikipedia.org/wiki/Game_Boy_Camera) (which has 2-bit color and fewer pixels).
>
> -- <cite>[PD-Camera project](https://github.com/t0mg/pd-camera/tree/main#pd-camera-project)</cite>

This firmware is based on a port of the original [PD-Camera project](https://github.com/t0mg/pd-camera) for the M5Stack CoreS3, which has been modified to work with the Freenove ESP32-S3-WROOM CAM board.

For more information about the original project, see [PD-Camera project](https://github.com/t0mg/pd-camera).

## PD-Camera for Freenove ESP32-S3-WROOM Features

- Connect your Freenove ESP32-S3-WROOM CAM board to the Playdate console and use it as a camera accessory.
- The Freenove board has an integrated OV2640 camera that's ready to use without additional hardware.
- The implementation uses both USB-C ports on the board - one for power supply and one for communication with the Playdate.
- Serial console output for debugging and monitoring camera status.
- Physical button support for system control (power off via deep sleep).

## Disclaimer

> This project is 
> - not affiliated with nor endorsed by [Panic Inc.](https://panic.com/), 
> - highly experimental,
> - very hacky,
>   - oh so hacky.
>
> While I crashed my own Playdate countless times working on this, and it has survived so far, I cannot be held responsible for any damage, data loss, bad selfie, pandemic, etc. that might occur to you while playing with this project. Use this at your own risk. Thanks ❤️.
>
> -- <cite>[PD-Camera project](https://github.com/t0mg/pd-camera/tree/main#disclaimer)</cite>

This Freenove port is highly experimental as well. Use it at your own risk!

## Hardware

The PD-Camera for Freenove ESP32-S3-WROOM CAM requires the following hardware:

- [Playdate](https://play.date) console
- [Freenove ESP32-S3-WROOM CAM](https://github.com/Freenove/Freenove_ESP32_S3_WROOM_Board) board
- Two USB-C cables (one for power, one for communication)

## Setup Instructions

1. Build and flash the firmware to your Freenove ESP32-S3-WROOM CAM board.
2. Install the companion app on your Playdate by sideloading the [PD-Camera project App](https://github.com/t0mg/pd-camera-app).
3. Connect one USB-C port of the Freenove board to a power source.
4. Connect the other USB-C port to your Playdate.
5. Run the companion app on your Playdate.
6. The camera should automatically connect and start working.

## Companion App

The companion app that needs to be sideloaded into Playdate can be the [PD-Camera project App](https://github.com/t0mg/pd-camera-app) from the original project.

## Building

This firmware is developed with [PlatformIO IDE for VSCode](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide). Please read [PlatformIO IDE for VSCode](https://docs.platformio.org/en/stable/integration/ide/vscode.html) for detailed build instructions.

To build the project:
1. Open the project in PlatformIO IDE
2. Select the `freenove_esp32s3_wroom` environment
3. Build and upload to your board

## Known Issues

- USB communication may be interrupted, and the companion app and firmware may freeze or crash.
- The board occasionally needs to be reset to reconnect to the Playdate.
- The camera quality is limited by the capabilities of the OV2640 sensor.
- [Known Issues](https://github.com/t0mg/pd-camera-app#known-issues) with the Companion App may be reproduced as well.

## Dependency Libraries

- [PD-Camera project](https://github.com/t0mg/pd-camera) by [t0mg](https://github.com/t0mg)
- [USB Host CDC-ACM Class Driver](https://github.com/espressif/idf-extra-components/tree/master/usb/usb_host_cdc_acm)
- [esp32-camera](https://github.com/espressif/esp32-camera) for the OV2640 camera driver
- [dithering_halftoning](https://github.com/deeptronix/dithering_halftoning) by [deeptronix](https://github.com/deeptronix)

## Special Thanks

- [t0mg](https://github.com/t0mg) for the original PD-Camera project
- The author of the M5Stack CoreS3 port that served as the base for this adaptation

----

Playdate is © [Panic Inc.](https://panic.com/) - this project isn't affiliated with or endorsed by them in any way.
 