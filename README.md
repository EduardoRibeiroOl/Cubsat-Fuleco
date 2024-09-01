# Arduino Environmental Monitoring System

This project is an Arduino-based environmental monitoring system that integrates a GPS module, an MQ-7 gas sensor, and an OLED display. The system is designed to continuously track carbon monoxide (CO) levels and provide real-time geographic location data. The information is displayed both on an OLED screen and in the Arduino serial monitor.

## Features

- **CO Level Monitoring**: Continuously measures and displays carbon monoxide (CO) concentration in parts per million (ppm) using the MQ-7 gas sensor.
- **GPS Data Tracking**: Captures and displays GPS data, including latitude, longitude, and altitude.
- **OLED Display**: Real-time display of CO concentration and GPS data on a 128x64 pixel OLED screen.
- **Serial Monitor Output**: Organized and easy-to-read output in the Arduino serial monitor for debugging and logging purposes.

## Components Used

- **Arduino Board** (e.g., Arduino Uno)
- **MQ-7 Gas Sensor**: Detects carbon monoxide levels in the environment.
- **GP-20U7 GPS Module**: Provides GPS data, including location coordinates.
- **OLED Display (SSD1306)**: Displays the data collected from the sensors.

## Libraries Required

- **SoftwareSerial**: To communicate with the GPS module via software-based serial communication.
- **Wire**: For I2C communication with the OLED display.
- **Adafruit GFX Library**: Graphics library for the OLED display.
- **Adafruit SSD1306**: Specific library for the SSD1306 OLED display.
- **MQUnifiedsensor**: Library for handling the MQ-7 gas sensor.

## Installation

1. Clone this repository to your local machine.
    ```sh
    git clone https://github.com/yourusername/arduino-environment-monitor.git
    ```

2. Install the required libraries using the Arduino Library Manager or by downloading them from the links below:
   - [SoftwareSerial](https://www.arduino.cc/en/Reference/SoftwareSerial)
   - [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library)
   - [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
   - [MQUnifiedsensor](https://github.com/miguel5612/MQSensorsLib)

3. Open the project in the Arduino IDE and upload the code to your Arduino board.

## Usage

1. Connect the GPS module, MQ-7 gas sensor, and OLED display to your Arduino board according to the pin configuration in the code.
2. Upload the code to your Arduino board.
3. Open the Serial Monitor in the Arduino IDE (set the baud rate to `9600`).
4. Observe the CO concentration and GPS data displayed on the OLED screen and serial monitor.

## Circuit Diagram

*Coming soon...*

## Example Output

Here is how the output will look on the serial monitor:
# Monitor Serial

## Sistema Iniciado...
========================

```plaintext
Leitura Atual:
------------------------
Concentração de CO: 25.36 ppm
Dados do GPS:
$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
------------------------

Leitura Atual:
------------------------
Concentração de CO: 25.78 ppm
Dados do GPS:
$GPGGA,123520,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*48
------------------------


