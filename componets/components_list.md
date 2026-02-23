# 📦 Components List  
## Automatic Water Level Indicator & Controller using Arduino

---

## 🛠 Hardware Components

| S.No | Component Name        | Specification     | Quantity | Description |
|------|----------------------|------------------|----------|------------|
| 1    | Arduino UNO          | ATmega328P       | 1        | Main microcontroller board used for system control |
| 2    | Ultrasonic Sensor    | HC-SR04          | 1        | Measures water level using ultrasonic echo principle |
| 3    | LCD Display          | 16x2 I2C         | 1        | Displays water percentage and pump status |
| 4    | Relay Module         | 5V SPDT          | 1        | Controls switching of water pump |
| 5    | Water Pump           | 12V DC           | 1        | Pumps water into the tank |
| 6    | Push Buttons         | Normally Open    | 2        | Used for SET and MODE control |
| 7    | Jumper Wires         | Male-Male / MF   | As req.  | For circuit connections |
| 8    | Breadboard / PCB     | Standard         | 1        | For assembling the circuit |
| 9    | Power Supply         | 5V / 12V DC      | 1        | Powers Arduino and pump |

---

## ⚙️ Software Requirements

| Software        | Purpose |
|----------------|----------|
| Arduino IDE    | Writing and uploading code |
| Proteus (Opt.) | Circuit simulation |
| Fritzing (Opt.)| Wiring diagram creation |

---

## 🔌 Pin Configuration Summary

| Arduino Pin | Connected To |
|------------|--------------|
| D8         | Ultrasonic Trigger |
| D9         | Ultrasonic Echo |
| D10        | SET Button |
| D11        | MODE Button |
| D12        | Relay Module |
| A4         | I2C SDA (LCD) |
| A5         | I2C SCL (LCD) |
| 5V         | Power Supply |
| GND        | Ground |

---

## 🔍 System Modules

- **Sensing Module** → Ultrasonic Sensor  
- **Processing Unit** → Arduino UNO  
- **Display Module** → 16x2 I2C LCD  
- **Control Module** → Relay + Pump  
- **Memory Module** → EEPROM (Tank height storage)  

---

## 📌 System Specifications

- Operating Voltage: 5V (Arduino), 12V (Pump)
- Detection Range: 2cm – 400cm (HC-SR04)
- Display Type: 16x2 Character LCD
- Control Mode: Auto / Manual
- Storage: EEPROM (Non-volatile memory)

---

## 👨‍💻 Author

**KADARI VENU**  
B.Tech – Electronics & Communication Engineering  
CVR College of Engineering
