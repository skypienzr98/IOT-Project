# IoT-Project
A simple IoT project for Software Engineering course (SKEL413) on a Agriculture Monitoring System using NodeMCU ESP8266 with Soil Moisture and LDR Sensor Module for data acquisition.
## Table of Contents

- [Stage 2: IoT Agriculture Monitoring System](#stage-2-iot-agriculture-monitoring-system)
  * [Problem Statement](#problem-statement)
    + [Use Case Description - Report and Notify Plant Condition](#use-case-description---report-and-notify-plant-condition)
  * [System Architecture](#system-architecture)
  * [Sensor](#sensor)
  * [Cloud Platform](#cloud-platform)
  * [Dashboard](#dashboard)
## Stage 2: IoT Agriculture Monitoring System

### Problem Statement

Food security has been listed in the 17 Sustainable Development Growth (17 SDGs) under 'Zero Hunger'. Agriculture is an important aspect of life as it could source an adequate foodstuff. It contributes to most of the world's food, one of the human's basic need of life. Hence, explains the importance of maintaining the quality of the crops. Cultivation of soil for the growth of crops has become the attention of all farmers. Frequent monitoring is required to ensure plants to grow healthily.

There are a few parameters that need to be monitored in growing a healthy crops which includes soil humidity and light intensity. A soil which is too humid could catalyst the growth of mold and bacteria that cause plants to wilt and become unhealthy whereas plants that does not receive enough lights will also become wilt and eventualy dies.

The intervention of Internet of Things (IoT) technology in agriculture could facilitate farmers in managing their crops by a proper schedule of plant monitoring. They need not to worry about the condition of their crops as the sensor will aid them to monitor the plants. The sensor senses the changes happen to the crops and immediately notify them for any changes occur and they can take action accordingly. This project will focus on the development of IoT-based agriculture monitoring system. 

[click here to return to the table of contents](#table-of-contents)

![Use case diagram](https://github.com/SolaireAstora125/IoT-Project/blob/main/asset/case-diagram-v2.jpg)

#### Use Case Description - Report and Notify Plant Condition

[click here to return to the table of contents](#table-of-contents)

| Elements | Description |
| ------- | ---------------|
| System | Farms or nursery |
| Use Case | Report and notify plant condition |
| Actors | Farms or nursery, Farmers |
| Data | Farms or nursery sends summary of collected data from the sensors such as soil humidity and acidity |
| Stimulus | Farms (Sensor location) establish communication link with the user to send and update requested data |
| Response | The summarized data are sent and displayed to the user for data analysis and user may take action accordingly based on the analyzed data |
| Comments | The plant's conditions need to be monitored every day. |

### System Architecture

This section present an overview of the system architecture of IoT Agriculture Monitoring System. This project use NodeMCU ESP8266 to control, process and transmit moisture and light intensity data received from soil moisture and ldr sensor. NodeMCU will communicate using HTTP data protocol transmission to Flask Web Framework for data ingestion. Then, Flask will store the data to PythonAnywhere Web Hoisting platform and finally update to simple dashboard using Grafana Web Application.

[click here to return to the table of contents](#table-of-contents)
![system architecture](https://github.com/SolaireAstora125/IoT-Project/blob/main/asset/architechture-stage2-v5.png)

### Sensor
Propose data transmission protocol is **Hyper-Text-Transfer-Protocol (HTTP)**. Propose device for this project are:

| Devices | Function |
| ------- | ---------------|
| NodeMCU ESP8266 | Control, process and transmit data to web framework using HTTP data transmission |
| Soil Moisture Sensor | To check moisture level of soil |
| LDR Sensor Module | To detect change of light intensity with light dependent resistor |
| CD4051B Multiplexer  | Soil moisture and LDR sensor need to share ADC pin via multiplexer since NodeMCU 8266 has only one ADC pinout|
 
 <details>
  <summary>Click to show the code for NodeMCU ESP8266</summary>
 
```

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// setup I/O sensor nodemcu---------------------------------
#define sensorpin A0
#define modepin 10
// WiFi detail----------------------------------------------
const char* ssid = "insert SSID";
const char* password = "insert password";
String serverName =  "http://api.circuits.my/request.php";
// global variable------------------------------------------
float mp = 0;       //moisture percentage
float li = 0;       //light intensity
int sensormode = 0; //swap sensor
// setup wifi port - http-----------------------------------
WiFiServer server(80);
//----------------------------------------------------------

void wificlient(){
  WiFiClient client;
  HTTPClient http;
  String api_key = "Put your API key";
  String device_id = "Put your device ID";
  String httpData = serverName + "?api=" + api_key + "&id=" + device_id + "&mp=" + String(mp) + "&li=" + String(li);
  http.begin(client, httpData); //Specify the URL
  int httpResponseCode = http.GET(); //Make the request
  if (httpResponseCode > 0) { //Check for the returning code
    String payload = http.getString();
    Serial.println(httpResponseCode);
    Serial.println(payload);
  }
  else {
    Serial.print("Error Code: ");
    Serial.println(httpResponseCode);
  }
  http.end(); //Free the resources
}

void setup(){
  Serial.begin(115200);
  // Setup pinmode-----------------------------
  pinMode(sensorpin, INPUT);
  pinMode(modepin, OUTPUT);
  // Connect to WiFi network-------------------
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server-------------------------
  server.begin();
  Serial.println("Server started");
  // Print the IP address---------------------
  Serial.print("Network IP Address: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  //------------------------------------------
}

void loop(){
  // read soil moisture sensor input---------------------------------------------
  digitalWrite(sensormode, LOW);
  mp = ( 100.00 - ( (analogRead(sensorpin)/1023.00) * 100.00 ) );
  Serial.print("Soil Moisture (%) = "); Serial.print(mp); Serial.println("%");
  delay(200);
  // read ldr sensor input-------------------------------------------------------
  digitalWrite(sensormode, HIGH);
  li = (analogRead(sensorpin)/1023.00) * 100.00 ;
  Serial.print("Light Intensity (%) = "); Serial.print(li); Serial.println("%");
  delay(200);
  // check WiFi connection-------------------------------------------------------
  if(WiFi.status() == WL_CONNECTED) wificlient();
  else Serial.println("WiFi Disconnected");
  delay(600);
  //-----------------------------------------------------------------------------
}

```
</details>

 [click here to return to the table of contents](#table-of-contents)
 
 ![image](https://github.com/SolaireAstora125/IoT-Project/blob/main/asset/hardware-diagram.png)
 ![image](https://github.com/SolaireAstora125/IoT-Project/blob/main/asset/nodemcu-pinout.png)

### Cloud Platform
This [video](https://www.google.com/) and [links](http://mohdafiqazizi.pythonanywhere.com/) shows the result of integrated [PythonAnywhere Web Hoisting](https://www.pythonanywhere.com/) with the [Flask Web Framework](https://flask.palletsprojects.com/en/2.2.x/).

[click here to return to the table of contents](#table-of-contents)

### Dashboard
The prototype dashboard will developed using Grafana Web Application. The dashboard mainly focus on **Graphical-User-Interface (GUI)** approach consist element of:
- icon - small picture represent sub-application
- cursor - as interactive between GUI element
- menu - information or data group together and placed at visible place

[click here to return to the table of contents](#table-of-contents)
 
![Dashboard](https://github.com/SolaireAstora125/IoT-Project/blob/main/asset/dashboard.png)

 
