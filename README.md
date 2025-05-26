# MiniBee

**MiniBee** is a presence and motion sensor designed for room-scale awareness. It combines the Arduino MKR WiFi 1010 with the Infineon BGT60LTR11AIP radar shield (`SHIELDAUTONOMBGT60TOBO1`) to detect motion with directionality using edge-based logic.

## Features

- Real-time detection of motion and direction (approaching/departing)
- Based on Infineon’s BGT60LTR11AIP radar
- Adapted from Infineon’s official example for embedded integration
- Designed to integrate with custom presence systems or cloud-connected services
- Minimalist 3D-printable case for compact indoor installation

## Hardware

- **MCU**: Arduino MKR WiFi 1010
- **Radar**: Infineon BGT60LTR11AIP on SHIELDAUTONOMBGT60TOBO1
- **Power**: USB or LiPo via MKR
- **Case**: Printed on Prusa (15mm height, 15% infill, PLA/ABS)

### Wiring

| Radar Pin | Arduino Pin |
|-----------|-------------|
| GND       | GND         |
| VIN       | 3.3V or 5V  |
| TD        | 15          |
| PD        | 16          |

## Firmware

Adapted from Infineon's `motionDetection` example (MIT licensed).

Path: [`firmware/motion_detection/motionDetection.ino`](firmware/motion_detection/motionDetection.ino)

The firmware logs movement status via Serial and is optimized for local edge detection.

## License

MIT License © Infineon Technologies AG, with modifications for MiniBee.
