#include <Wire.h>
#include <MPU6050_tockn.h>
#include <VirtualWire.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>

const int txPin = 2;      // RF Transmitter connected to pin D2
const int dhtPin = 3;     // DHT22 connected to pin D7
const int ledPin = 7;     // LED connected to pin D7 (for blinking fun)

#define DHTTYPE DHT22     // Define DHT sensor type

MPU6050 mpu6050(Wire);
Adafruit_BMP085 bmp;
DHT dht(dhtPin, DHTTYPE);

struct SensorData {
  int X, Y, Z;       // MPU6050 Angles
  float temperature; // BMP180 Temperature (°C)
  float pressure;    // BMP180 Pressure (hPa)
  float altitude;    // BMP180 Altitude (m)
  float humidity;    // DHT22 Humidity (%)
} DATA;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  // Initialize sensors
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  bmp.begin();
  dht.begin();

  // Setup RF transmitter
  vw_set_tx_pin(txPin);
  vw_setup(4000); // Set data rate to 2000 bps

  // Set LED pin as OUTPUT
  pinMode(ledPin, OUTPUT);

  Serial.println("Transmitter Ready...");
}

void loop() {
  // Read MPU6050 data
  mpu6050.update();
  DATA.X = mpu6050.getAngleX();
  DATA.Y = mpu6050.getAngleY();
  DATA.Z = mpu6050.getAngleZ();

  // Read BMP180 data
  DATA.temperature = bmp.readTemperature();
  DATA.pressure = bmp.readPressure() / 100.0;  // Convert to hPa
  DATA.altitude = bmp.readAltitude();

  // Read DHT22 data
  DATA.humidity = dht.readHumidity();

  // Print sensor data
  Serial.print("TX -> X: "); Serial.print(DATA.X);
  Serial.print(" Y: "); Serial.print(DATA.Y);
  Serial.print(" Z: "); Serial.print(DATA.Z);
  Serial.print(" Temp: "); Serial.print(DATA.temperature);
  Serial.print("C Hum: "); Serial.print(DATA.humidity);
  Serial.print("% Pres: "); Serial.print(DATA.pressure);
  Serial.print(" hPa Alt: "); Serial.print(DATA.altitude);
  Serial.println(" m");

  // Blink LED (for fun 🎉)
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);

  // Transmit data
  vw_send((uint8_t*)&DATA, sizeof(DATA));
  vw_wait_tx();

  delay(1000); // Delay to prevent flooding
}
