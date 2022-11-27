# IoT-Project

## Stage 2: IoT Student Counting System

### Problem Statement

Food court in meranti often experiences losses when students go back home during holidays. This can be in the form of inefficient work hours of the general worker(dishwasher & cleaner), or losses when the food in the food court is not bought. 

To combat this, Firefoxes come up with the idea of counting the number of students that went to the meranti food court and store it in the cloud to be further analysed. The number, time, date and frequency is stored so that Meranti’s management can plan food distribution and staff work hours. This could also help in the planning of renovation/maintenance of the food court when it is necessary, as we know, the daytime maintenance should be performed only when the number of customers are minimal. 

### System Architecture

## Input(Sensors)
Laser sensors will read the input and send to controller
## Arduino/NodeMCU (controller)
Controller will receive data from sensor and upload it to the server
## Cloud Platform
Cloud will process data from the controller, analyze it and store the analyzed data in its memory. Finally, the analyzed data will be sent to the dashboard.
## Dashboard
Users could easily monitor the analyzed data in graph, pie chart and power conclusion and developers could review the data collecting process from here.


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

 
