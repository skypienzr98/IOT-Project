# IoTproject
An IoT project for SKEL 4213 on student counting system using Arduino with KY008 laser diode module to obtain the required data.
## IoT Student Counting System 
### Problem Statement

*Food court in meranti often experiences losses when students go back home during holidays. This can be in the form of inefficient work hours of the general worker(dishwasher & cleaner), or losses when the food in the food court is not bought.* 

*To combat this, Firefoxes come up with the idea of counting the number of students that went to the meranti food court and store it in the cloud to be further analysed. The number, time, date and frequency is stored so that Meranti’s management can plan food distribution and staff work hours. This could also help in the planning of renovation/maintenance of the food court when it is necessary, as we know, the daytime maintenance should be performed only when the number of customers are minimal.*

<strong><ins>Our Solution</ins></strong>

An IoT application to automate the manual checking rubbish bins that is already full or not, and pass the information to a dashboard where users could locate any available bins that are available.

<strong><ins>Use Case Diagram</ins></strong>

<p align="center">
<img src="Images/case_diagram.png">
</p>

### System Architecture

<img width="803" alt="Screenshot 2022-11-28 at 4 49 57 AM" src="https://user-images.githubusercontent.com/117338905/204159004-f99f4658-d9a6-40ba-9ae4-6aa7b95e86bd.png">

<strong><ins>Input(Sensors)</ins></strong>

Laser sensors will read the input and send to controller

<strong><ins>Arduino/NodeMCU (controller)</ins></strong>

Controller will receive data from sensor and upload it to the server

<strong><ins>Cloud Platform</ins></strong>

Cloud will process data from the controller, analyze it and store the analyzed data in its memory. Finally, the analyzed data will be sent to the dashboard.

<strong><ins>Dashboard</ins></strong>

Users could easily monitor the analyzed data in graph, pie chart and power conclusion and developers could review the data collecting process from here.

Below are the general overview of the system architecture for our IoT waste management system. For this project we will be using **ESP 8266** as our microcontroller device and it will be connected to **HC-SR04** ultrasonic sensor to obtain the capacity level of rubbish bins. The device will communicate using **HTTP** data protocol transmission and it will send the data to a **REST-API** implemented in **Flask** before later on hosted by **Heroku** Cloud platform and finally display the data on our simple dashboard app which we will be build using **Figma**. 

<img src="Images/system_arc.png">

### Hardware
<strong><ins>ESP 8266</ins></strong>

<img src="Images/esp8266.png" width="173" height="308">

<strong><ins>HC-SR04</ins></strong>

<img src="Images/hc_sr04.jpg" width="256" height="197">

<strong><ins>Circuit Diagram</ins></strong>

<img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/06/ESP8266-Ultrasonic-Sensor-Wiring-Fritzing-Diagram.png?w=738&quality=100&strip=all&ssl=1" width="318" height="258">

<strong>Code Sample</strong>

<details>
  <summary>Please Click Me</summary>

  ```
//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034


long duration;
float distanceCm;

const int trigPin = 12;
const int echoPin = 14;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = (duration * SOUND_VELOCITY/2)-1;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  delay(1000);
}
  ```
</details>


### Cloud Platform

The following [video](https://youtu.be/W6meRlzatVE) shows the process on how to deploy our Django application using PythonAnywhere. This is the [link](http://skypienzr98.pythonanywhere.com/) to our application website shown in the video.
 
### Dashboard

<img width="949" alt="Screenshot 2022-11-28 at 4 43 24 AM" src="https://user-images.githubusercontent.com/117338905/204158752-4d1dd1b6-ae96-45b0-b55f-386d103a1c0f.png">



