# ESP32 SHT1x Sensor with BLE and WiFi Configuration

This project demonstrates how to read temperature and humidity values from an SHT1x sensor using an ESP32 and transmit them over BLE. Additionally, it includes functionality to receive WiFi credentials over BLE and connect to a WiFi network.

## Table of Contents
- [Introduction](#introduction)
- [Components Required](#components-required)
- [Circuit Diagram](#circuit-diagram)
- [Code Explanation](#code-explanation)
- [How to Use](#how-to-use)
- [Screenshots](#screenshots)
- [Demonstration Video](#demonstration-video)
- [Credits](#credits)

## Introduction
This project demonstrates how to read temperature and humidity values from an SHT1x sensor using an ESP32 and transmit them over BLE. Additionally, it includes functionality to receive WiFi credentials over BLE and connect to a WiFi network.

## Components Required
- ESP32 Development Board
- SHT1x Sensor
- Jumper Wires
- Breadboard
- nRF Connect app (or any BLE client)

## Circuit Diagram
Connect the SHT1x sensor to the ESP32 as follows:
- SHT1x Data Pin -> GPIO 4
- SHT1x Clock Pin -> GPIO 5
- SHT1x VCC -> 3.3V
- SHT1x GND -> GND

## How to Use
1. **Setup Hardware:**
   - Connect the SHT1x sensor to the ESP32 as per the circuit diagram.
2. **Upload Code:**
   - Upload the provided code to the ESP32 using the Arduino IDE.
3. **Connect with BLE:**
   - Open the nRF Connect app and connect to the ESP32. The temperature and humidity values should be displayed in readable format.
4. **Send WiFi Credentials:**
   - Use the BLE client to send WiFi credentials to the ESP32 (this part is optional and requires additional setup).

## Demonstration Video
[Watch the video demonstration](https://youtu.be/nnvIznbix3o)
Here, in this channel you may found more videos related to it.



