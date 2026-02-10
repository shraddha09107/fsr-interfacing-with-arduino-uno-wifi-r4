# FSR Interfacing with Arduino UNO WiFi R4

This project demonstrates how to interface a Force Sensitive Resistor (FSR) with the Arduino UNO WiFi R4 microcontroller and read analog sensor values via serial communication.

## Hardware Requirements

- **Arduino UNO WiFi R4** - Microcontroller board
- **FSR (Force Sensitive Resistor)** - Pressure-sensitive sensor
- **10K Ohm Resistor** - Pull-down resistor for the FSR voltage divider circuit
- **USB Cable** - For programming and serial communication
- **Breadboard and Jumper Wires** - For circuit connections

## Circuit Diagram

The FSR and 10K pull-down resistor form a voltage divider circuit:

```
+5V
 |
[FSR]
 |
 +------ A0 (analog input)
 |
[10K Resistor]
 |
GND
```

## Software Setup

### Prerequisites

- **PlatformIO** - Build system and IDE extension
- **VSCode or CLion** - Integrated Development Environment

### Installation

1. Clone or download this project
2. Open the project in your IDE with PlatformIO installed
3. Update `platformio.ini` if your serial port differs from `COM11`

## Configuration

Edit `platformio.ini` to match your system:

```ini
[env:uno_r4_wifi]
platform = renesas-ra
board = uno_r4_wifi
framework = arduino
monitor_port = COM11        ; Change to your COM port
monitor_speed = 9600
upload_port = COM11         ; Change to your COM port
```

To find your COM port on Windows:
- Device Manager → Ports (COM & LPT) → Arduino UNO WiFi R4

## Usage

### Building and Uploading

1. Connect your Arduino UNO WiFi R4 via USB
2. Build the project:
   ```
   platformio run -e uno_r4_wifi
   ```
3. Upload to the board:
   ```
   platformio run -e uno_r4_wifi -t upload
   ```

### Reading Serial Data

1. Open the serial monitor:
   ```
   platformio device monitor -p COM11 -b 9600
   ```
2. Apply pressure to the FSR to see analog readings change (0-1023)
3. Readings update every 300ms

## How It Works

- The FSR is read on **Analog Pin A0**
- Raw analog values range from **0 (no pressure) to 1023 (maximum pressure)**
- Values are printed to the Serial Monitor at 9600 baud
- The sample rate is **300ms** (adjustable in code)

## Code Structure

**main.cpp:**
- `setup()` - Initializes serial communication
- `loop()` - Continuously reads FSR analog value and prints to serial

## Customization

To adjust the sampling rate, modify the delay in `src/main.cpp`:

```cpp
delay(300);  // Change this value (in milliseconds)
```

## Troubleshooting

| Issue | Solution |
|-------|----------|
| No serial output | Check USB connection and correct COM port in `platformio.ini` |
| Unstable readings | Ensure FSR connections are secure; check 10K resistor quality |
| Arduino not detected | Install CH340 drivers (Windows) or verify USB cable |
| Readings stuck at 0 or 1023 | Check FSR wiring and pull-down resistor connection |

## Project Structure

```
fsr-interfacing-with-arduino-uno-wifi-r4/
├── platformio.ini          # PlatformIO configuration
├── src/
│   └── main.cpp           # Main sketch
├── include/               # Header files (optional)
├── lib/                   # Libraries (optional)
└── README.md             # This file
```

## References

- [Arduino UNO WiFi R4 Documentation](https://docs.arduino.cc/hardware/uno-r4-wifi)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [FSR Sensor Information](https://learn.adafruit.com/force-sensitive-resistor-fsr)

## License

This project is open source and available under the MIT License.

## Author

Created for Arduino development with FSR sensors.

