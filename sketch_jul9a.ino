#include <NimBLEDevice.h>
#include <SHT1x-ESP.h>

// Define data and clock pins for SHT10
#define dataPin  4  // SHT10 data pin connected to GPIO 4 of ESP32
#define clockPin 5  // SHT10 clock pin connected to GPIO 5 of ESP32

// Create an instance of the SHT1x sensor
SHT1x sht1x(dataPin, cloESckPin);

// BLE settings
#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID "abcdef12-1234-5678-1234-56789abcdef1"
#define TEMP_CHARACTERISTIC_UUID "abcdef12-1234-5678-1234-56789abcdef2"

NimBLECharacteristic *pCharacteristic;
NimBLECharacteristic *pTempCharacteristic;
bool deviceConnected = false;

class MyServerCallbacks: public NimBLEServerCallbacks {
  void onConnect(NimBLEServer* pServer) {
    deviceConnected = true;
  }

  void onDisconnect(NimBLEServer* pServer) {
    deviceConnected = false;
  }
};

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  delay(1000); // Allow time for serial monitor to start
  Serial.println("SHT10 sensor reading example with ESP32");

  // Initialize BLE
  NimBLEDevice::init("ESP32_SHT10");
  NimBLEServer *pServer = NimBLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  NimBLEService *pService = pServer->createService(SERVICE_UUID);

  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      NIMBLE_PROPERTY::READ | 
                      NIMBLE_PROPERTY::NOTIFY
                    );

  pTempCharacteristic = pService->createCharacteristic(
                          TEMP_CHARACTERISTIC_UUID,
                          NIMBLE_PROPERTY::READ | 
                          NIMBLE_PROPERTY::NOTIFY
                        );

  pService->start();
  NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();
}

void loop() {
  if (deviceConnected) {
    float temperatureC = sht1x.readTemperatureC();
    float humidity = sht1x.readHumidity();
    
    // Create strings for temperature and humidity
    String tempString = "Temperature: " + String(temperatureC, 2) + " °C";
    String humidityString = "Humidity: " + String(humidity, 2) + " %";
    
    // Update characteristics with new values
    pCharacteristic->setValue(humidityString.c_str());
    pCharacteristic->notify(); // Notify the connected device
    
    pTempCharacteristic->setValue(tempString.c_str());
    pTempCharacteristic->notify(); // Notify the connected device
    
    Serial.println(tempString);
    Serial.println(humidityString);
  }
  
  delay(2000); // Wait for 2 seconds before the next reading
}