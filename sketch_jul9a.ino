#include <NimBLEDevice.h>
#include <SHT1x-ESP.h>

// Define data and clock pins for SHT1x
#define dataPin  4  // SHT1x data pin connected to GPIO 4 of ESP32
#define clockPin 5  // SHT1x clock pin connected to GPIO 5 of ESP32

// Create an instance of the SHT1x sensor
SHT1x sht1x(dataPin, clockPin);

// BLE settings
#define SERVICE_UUID               "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID        "abcdef12-1234-5678-1234-56789abcdef1"
#define TEMP_CHARACTERISTIC_UUID   "abcdef12-1234-5678-1234-56789abcdef2"

NimBLEServer *pServer;
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
  Serial.println("SHT1x sensor reading example with ESP32");

  // Initialize BLE
  NimBLEDevice::init("ESP32_SHT1x");
  pServer = NimBLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  NimBLEService *pService = pServer->createService(SERVICE_UUID);

  // Create characteristics
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

  // Start the service
  pService->start();

  // Start advertising
  NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(pService->getUUID());
  pAdvertising->start();
}

void loop() {
  if (deviceConnected) {
    // Read sensor data
    float temperatureC = sht1x.readTemperatureC();
    float humidity = sht1x.readHumidity();
    
    // Convert float values to strings
    String tempString = String(temperatureC, 2) + " °C";
    String humidityString = String(humidity, 2) + " %";
    
    // Update characteristics with new values
    pTempCharacteristic->setValue(tempString.c_str());
    pTempCharacteristic->notify(); // Notify the connected device
    
    pCharacteristic->setValue(humidityString.c_str());
    pCharacteristic->notify(); // Notify the connected device
    
    Serial.print("Temperature: ");
    Serial.print(tempString);
    Serial.println(" °C");
    
    Serial.print("Humidity: ");
    Serial.print(humidityString);
    Serial.println(" %");
  }
  
  delay(2000); // Wait for 2 seconds before the next reading
}
