# IoTproject
An IoT project for SKEL 4213 on student counting system using Arduino with KY008 laser diode module to obtain the required data.
## IoT Student Counting System 
### 1. Problem Statement

*Food court in meranti often experiences losses when students go back home during holidays. This can be in the form of inefficient work hours of the general worker(dishwasher & cleaner), or losses when the food in the food court is not bought.* 

*To combat this, Firefoxes come up with the idea of counting the number of students that went to the meranti food court and store it in the cloud to be further analysed. The number, time, date and frequency is stored so that Meranti’s management can plan food distribution and staff work hours. This could also help in the planning of renovation/maintenance of the food court when it is necessary, as we know, the daytime maintenance should be performed only when the number of customers are minimal.*

<strong><ins>Our Solution</ins></strong>

An IoT application to count how many student coming in to food court and pass the information to a dashboard where users could track crowdedness of specific location.


### 2. System Architecture

<img width="803" alt="Screenshot 2022-11-28 at 4 49 57 AM" src="https://user-images.githubusercontent.com/117338905/204159004-f99f4658-d9a6-40ba-9ae4-6aa7b95e86bd.png">

**Input(Sensors)**-
Laser sensors will read the input and send to controller

**Arduino/NodeMCU (controller)**-
Controller will receive data from sensor and upload it to the server

**Cloud Platform**-
Cloud will process data from the controller, analyze it and store the analyzed data in its memory. Finally, the analyzed data will be sent to the dashboard.

**Dashboard**-
Users could easily monitor the analyzed data in graph, pie chart and power conclusion and developers could review the data collecting process from here.

### 3. Sensors
Showing below are the possible choice of sensors that might be used in this project. These sensors are used to detect the movement of customers that come to the food court. 

A. <strong><ins>LDR sensor</ins></strong> 

Laser sensor usually are combination of laser diode and photoresistor(LDR). This sensor can detect whether an object is blocking the resistors as the laser diode are always pointed towards the the LDR. 
[KY008 Laser Diode Module + Receiver Sensor For Arduino](https://shopee.com.my/KY008-Laser-Diode-Module-Receiver-Sensor-For-Arduino-i.132528683.2035527098?sp_atk=ea2b0a91-1a0d-4c03-9f15-461c31224bae&xptdk=ea2b0a91-1a0d-4c03-9f15-461c31224bae)

<img width="208" alt="Screenshot 2022-11-28 at 5 18 46 AM" src="https://user-images.githubusercontent.com/117338905/204160209-393cd333-ba73-4ad3-91a2-5c1be24c4f5f.png">

B. <strong><ins>Ultrasonic sensors</ins></strong> 

This sensor are not only can detect the presence of object that it is pointed to, but it can also detect the distances
[HC-SR04 Ultrasonic Range Detector Distance Sensor](https://shopee.com.my/HC-SR04-Ultrasonic-Range-Detector-Distance-Sensor-(2cm-400cm)-3mm-Resolution-SR-04-i.126211897.7563296073?sp_atk=084eace9-96d5-4719-a3e6-798fbe7af4df&xptdk=084eace9-96d5-4719-a3e6-798fbe7af4df) 

<img width="202" alt="Screenshot 2022-11-28 at 5 20 05 AM" src="https://user-images.githubusercontent.com/117338905/204160239-3fecaedb-3210-4174-ade0-ae12f5275574.png">

### 4. Cloud Platform

The following [video](https://youtu.be/W6meRlzatVE) shows the process on how to deploy our Django application using PythonAnywhere. This is the [link](http://skypienzr98.pythonanywhere.com/) to our application website shown in the video.
 
### 5. Dashboard

<img width="949" alt="Screenshot 2022-11-28 at 4 43 24 AM" src="https://user-images.githubusercontent.com/117338905/204158752-4d1dd1b6-ae96-45b0-b55f-386d103a1c0f.png">



