# CUBESAT🛰
<p align="center">
  <img src="https://github.com/user-attachments/assets/e1892cf2-5e6f-447d-8518-ef1c0f62273d" width="400">
</p>



 ## Blueprint
The CubeSat is built using an Arduino Nano, DHT22 for temperature and humidity, BMP180 for altitude, NEO-6M GPS for location, MPU6050 for orientation, and a 433 MHz RF module for wireless communication. A 18650 battery with a step-down module powers the system, and a patch antenna helps with signal transmission. First, a circuit diagram is made, and each component is tested separately before combining everything into a single program. A PCB is designed, manufactured, and assembled after testing the system for sensor accuracy and communication. Once complete, the CubeSat can track weather, altitude, and location while sending real-time data to a receiver. Future improvements may include longer-range communication and solar power. 🚀📡 

## **CubeSat Goals**  
- **Calibrate Sensors** – Ensure all sensors give correct readings.  
- **Send Data** – Transmit real-time altitude, temperature, humidity, pressure, and location using the 433 MHz RF module.  
- **Save Data** – Store sensor readings for later use.  
- **Track Weather & Altitude** – Measure environmental conditions.  
- **Find Location** – Update GPS coordinates in real-time.  
- **Communicate Wirelessly** – Use a patch antenna for stable data transmission.  
- **Manage Power** – Use the 18650 battery efficiently.  

## Hardware & Sensor Data  
| **Component**          | **Pinout**   |
|------------------------|----------------------|
| **Arduino Nano**       | -                    |
| **DHT22**             | D2 (Data)            |
| **BMP180**            | A4 (SDA), A5 (SCL)   |
| **NEO-6M GPS**        | D3 (TX), D4 (RX)     |
| **MPU6050**           | A4 (SDA), A5 (SCL)   |
| **433 MHz RF Module** | D8 (TX), D9 (RX)     |
| **Patch Antenna**      | Connected to RF Module |
| **18650 Battery**      | VIN, GND             |
| **Step-Down Module**   | 3.7V to 5V for Nano  |

## Data visualization from CubeSat in Serial Monitor (RECIEVER) 
<p align="center">
  <img src="https://github.com/user-attachments/assets/efabf47a-d3a8-4907-819a-d8dd1e9e55dd" width="900">
</p>







