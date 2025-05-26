# MiniBee: Radar-Based Presence Sensor

MiniBee is a compact presence detector built using the Arduino MKR WiFi 1010 and the Infineon BGT60LTR11AIP radar sensor. It’s designed for real-time interaction systems — detecting motion and simulating presence through a simple logic signal. It’s ideal for installations, responsive spaces, and integration with creative tools like TouchDesigner.

---

## 🚀 Features

* **Radar presence detection** (BGT60LTR11AIP)
* **Edge logic** for maintaining presence state
* **Serial communication** of logic signal (`1` = presence, `0` = no presence)
* **Integration with TouchDesigner** via `.toe` file
* **Custom 3D-printed case**

---

## 🧠 How It Works

The radar detects motion. If motion is detected, the device outputs a `1`. If no motion is detected for 15 seconds, it outputs a `0`. This creates a presence-like behavior based on movement.

This logic is implemented in the firmware and also interpreted in the TouchDesigner patch.

---

## 🛠️ Hardware

* **MCU**: Arduino MKR WiFi 1010
* **Radar Sensor**: Infineon BGT60LTR11AIP (mounted via `SHIELDAUTONOMBGT60TOBO1`)
* **Power**: USB / LiPo (optional)
* **Case**: Custom 3D-printed (STL provided)

### Wiring

| Shield Pin | Arduino Pin | Description      |
| ---------- | ----------- | ---------------- |
| TD         | D15         | Target Detect    |
| PD         | D16         | Phase Detect     |
| VIN        | VCC         | Power 3.3V or 5V |
| GND        | GND         | Ground           |

---

## 📂 Repository Structure

```
minibee/
├── firmware/
│   └── motion_detection/
│       ├── motionDetection.ino         # Main radar firmware
│       └── README.md
├── hardware/
│   └── case_3d_print/
│       └── minibee_case_v1.stl         # 3D printable case
├── touchdesigner/
│   └── minibee_presence_reader.toe     # Reads serial and outputs logic signal
├── LICENSE
├── .gitignore
└── README.md
```

---

## 🎛️ TouchDesigner Integration

The included `.toe` patch reads serial input (`1` or `0`) and outputs a logic signal as a CHOP. It maintains a "presence" state for 15 seconds after the last motion detection.

### File

* `touchdesigner/minibee_presence_reader.toe`

### Behavior

| Serial Value | CHOP Output | Description                       |
| ------------ | ----------- | --------------------------------- |
| `1`          | 1           | Motion detected (presence active) |
| `0`          | 0           | No motion (after 15s timeout)     |

This is ideal for driving installations, triggers, lights, or generative visuals.

---

## 📎 License

MIT — Feel free to use, adapt, and build upon it.

Copyright 2025
