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

Here are some screenshorts and pictures which are related to the work
1st pic is the layout of circuit here is the link 
![pic 1](https://github.com/prajjwal111/ESP32_SHT1x_BLE_WiFi-/assets/175052069/ce4e36d0-0b62-49d8-b80a-7d12fa311c56)

2nd pic is ESP-32 WROOM OUTPUT
![WhatsApp Image 2024-07-10 at 23 03 50_82e47183](https://github.com/prajjwal111/ESP32_SHT1x_BLE_WiFi-/assets/175052069/c774036f-131b-42bd-901f-04894008e9ab)

3rd pic is actual circuit design with ESP-32 WROOM WITH SHT SENSOR
![WhatsApp Image 2024-07-10 at 23 03 55_020d5e63](https://github.com/prajjwal111/ESP32_SHT1x_BLE_WiFi-/assets/175052069/bb48dd84-83cf-495c-b15e-45604cfbd324)

Now last is nRF-connect app result pics 
![WhatsApp Image 2024-07-10 at 23 03 52_72e4ad3e](https://github.com/prajjwal111/ESP32_SHT1x_BLE_WiFi-/assets/175052069/fe43968d-011a-401a-bd78-cbca7c499e8e)
![WhatsApp Image 2024-07-10 at 23 03 53_003cb009](https://github.com/prajjwal111/ESP32_SHT1x_BLE_WiFi-/assets/175052069/512fb4b2-5869-4af2-8099-85f9aab6f2d0)
![WhatsApp Image 2024-07-10 at 23 03 54_96895be0](https://github.com/prajjwal111/ESP32_SHT1x_BLE_WiFi-/assets/175052069/92ac30c7-303a-4c29-b8bd-b45bd52c7b8d)
![WhatsApp Image 2024-07-10 at 23 03 52_18447bd5](https://github.com/prajjwal111/ESP32_SHT1x_BLE_WiFi-/assets/175052069/e26b513c-d9b0-4926-b960-af7904e3af4b)








