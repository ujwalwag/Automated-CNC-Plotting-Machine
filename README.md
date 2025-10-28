Automated CNC Plotting Machine (Academic Project)

An open-source, scalable precision farming system to automate crop manufacturing and nurturing.

This project is an academic exploration into precision agriculture, featuring a CNC-based system designed to automate critical farming tasks like plowing, seeding, and watering. It leverages a network of sensors and microcontrollers to make intelligent, real-time decisions, enhancing food production while optimizing resource consumption.

Objective

To develop and demonstrate an open-source and scalable precision farming system. The core of this project is an innovative CNC Potting Machine that utilizes automation and real-time data to revolutionize farming practices, making them more efficient and cost-effective.

Key Features

Intelligent Automation: The system is orchestrated by an Arduino Mega 2560 microcontroller, which automates various critical functions throughout the farming process.

Real-time Sensor Network: Utilizes an array of sensors, including soil moisture sensors and IR sensors, to continuously monitor essential parameters like soil conditions and tray positions.

Data-Driven Decisions: The collected sensor data empowers the system to make intelligent decisions, enabling precise tasks such as plowing, seeding, and watering with high accuracy.

Precision Control: Incorporates NEMA 17 stepper motors and A4988 stepper motor drivers to ensure precise, repeatable control over the multifunctional tools used in the farming process.

Open-Source & Scalable: Built with an open-source philosophy, this project is designed to be highly flexible, scalable, and adaptable to various crops, pot sizes, and farming environments.

Core Components & Technologies

Microcontroller: Arduino Mega 2560

Motors: NEMA 17 Stepper Motors

Motor Drivers: A4988 Stepper Motor Drivers

Sensors:

Soil Moisture Sensors

IR Sensors (for positioning)

Framework: Open-Source Hardware & Software



Prerequisites

Installation & Setup

Hardware Assembly:

Assemble the CNC gantry and frame.

Wire the NEMA 17 motors to the A4988 drivers as per the schematic.

Connect the drivers and sensors to the Arduino Mega 2560.

Software Setup:

Clone this repository: git clone [YOUR_REPO_URL]

Open the .ino file in the Arduino IDE.

Install the required libraries (e.g., AccelStepper).

Upload the code to your Arduino Mega.

Future Work

This project serves as a strong foundation for further development. Potential next steps include:

Web Dashboard: Creating a web-based dashboard to monitor sensor data and control the machine remotely.

Machine Vision: Integrating a camera for computer vision tasks, such as weed detection or plant health analysis.

Scalability Testing: Adapting the design for larger-scale farming plots.

Read the project document [here]()
