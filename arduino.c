/**
 * Automated CNC Potting Machine
 * * This code is the main control program for the Arduino Mega 2560.
 * It controls the stepper motors, servo, sensors, and actuators
 * to perform the automated farming tasks.
 */

#include <Servo.h> 

// Pin Definitions

// -- Actuators & Tools --
int servoPin = 9;      // Servo motor for seeding mechanism
int conveyor = 22;     // Relay/pin for conveyor belt motor
int pump = 24;         // Relay/pin for water pump
int drill = 26;        // Relay/pin for plow/drill motor

// -- Stepper Motors (Y and Z axes) --
int stepPinY = 3;      // Y-axis step pin
int dirPinY = 4;       // Y-axis direction pin
int stepPinZ = 5;      // Z-axis step pin
int dirPinZ = 6;       // Z-axis direction pin

// -- Sensors --
const int irSensor = 7;    // IR sensor for tray/pot position detection
const int soilSensor = A0; // Soil moisture sensor (Analog pin)

// Global Variables
Servo servo;         // Servo object
int angle = 0;       // Current angle for the servo
int sensorValue = 0; // Variable to store soil sensor reading

void setup() {
  // Set pin modes for all sensors and actuators
  
  // --- Inputs ---
  pinMode(irSensor, INPUT);
  pinMode(soilSensor, INPUT); // Analog pins are INPUT by default, but explicit is good

  // --- Outputs ---
  pinMode(conveyor, OUTPUT);
  pinMode(drill, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);
  pinMode(stepPinZ, OUTPUT);
  pinMode(dirPinZ, OUTPUT); // Corrected from duplicate stepPinZ in doc
  
  // Attach the servo to its pin
  servo.attach(servoPin);
}

/**
 * Main control loop.
 * This appears to be a sequential demonstration of all components.
 */
void loop() {
  
  // 1. Move conveyor belt
  {
    digitalWrite(conveyor, HIGH); // Turn conveyor ON
    delay(5000);
    digitalWrite(conveyor, LOW);  // Turn conveyor OFF
    delay(5000);
  }

  // 2. Move Z-axis down (e.g., for watering or drilling)
  {
    digitalWrite(dirPinZ, LOW); // Set Z-axis direction (e.g., DOWN)
    digitalWrite(stepPinZ, HIGH);
    delay(5000); // Note: This method of stepping is not standard.
    digitalWrite(stepPinZ, LOW); // Usually a loop is needed for multiple steps.
    delay(5000);
    delay(1000);
  }

  // 3. Run water pump
  {
    digitalWrite(pump, HIGH); // Turn pump ON
    delay(6000);
    digitalWrite(pump, LOW);  // Turn pump OFF
    delay(5000);
  }

  // 4. Move Z-axis up
  {
    digitalWrite(dirPinZ, HIGH); // Set Z-axis direction (e.g., UP)
    digitalWrite(stepPinZ, HIGH);
    delay(5000);
    delay(1000);
  }
  
  // 5. Run drill/plow motor
  {
    digitalWrite(drill, HIGH); // Turn drill ON
    delay(8000);
    digitalWrite(drill, LOW);  // Turn drill OFF
    delay(5000);
  }

  // 6. Operate servo (seeding mechanism sweep)
  // Scan from 0 to 180 degrees
  for (angle = 0; angle < 180; angle++) {
    servo.write(angle);
    delay(1);
  }
  
  // Scan back from 180 to 0 degrees
  for (angle = 180; angle > 0; angle--) {
    servo.write(angle);
    delay(1);
  }

  // 7. Move Z-axis down again
  {
    digitalWrite(dirPinZ, LOW); // Set Z-axis direction (e.g., DOWN)
    digitalWrite(stepPinZ, HIGH);
    delay(1000);
    digitalWrite(stepPinZ, LOW);
    delay(1000);
    delay(1000);
  }

  // 8. Move Y-axis
  {
    digitalWrite(dirPinY, LOW); // Set Y-axis direction
    digitalWrite(stepPinY, HIGH);
    delay(1000);
    digitalWrite(stepPinY, LOW);
    delay(1000);
    delay(1000);
  }
  
  // The loop will now repeat this entire sequence.
}
