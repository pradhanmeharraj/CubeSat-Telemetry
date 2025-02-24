#include <VirtualWire.h>

const int rxPin = 11; // RF Receiver connected to pin D11

struct SensorData {
  int X, Y, Z;       // MPU6050 Angles
  float temperature; // BMP180 Temperature (°C)
  float pressure;    // BMP180 Pressure (hPa)
  float altitude;    // BMP180 Altitude (m)
  float humidity;    // DHT22 Humidity (%)
} DATA;

void setup() {
  Serial.begin(9600);
  vw_set_rx_pin(rxPin);
  vw_setup(2000); // Set data rate to 2000 bps
  vw_rx_start();  // Start receiving

  Serial.println("Receiver Ready...");
}

void loop() {
  uint8_t buf[sizeof(SensorData)];
  uint8_t buflen = sizeof(SensorData);

  if (vw_get_message(buf, &buflen)) { // Check for incoming data
    memcpy(&DATA, buf, sizeof(DATA));

    // Print received data
    Serial.print("RX -> X: "); Serial.print(DATA.X);
    Serial.print(" Y: "); Serial.print(DATA.Y);
    Serial.print(" Z: "); Serial.print(DATA.Z);
    Serial.print(" Temp: "); Serial.print(DATA.temperature);
    Serial.print("C Hum: "); Serial.print(DATA.humidity);
    Serial.print("% Pres: "); Serial.print(DATA.pressure);
    Serial.print(" hPa Alt: "); Serial.print(DATA.altitude);
    Serial.println(" m");
  }
}
