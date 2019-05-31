# group-08

### Content table
1. <a href="#ourproject">Our Project</a>
2. <a href="#installation">Installation</a>
3. <a href="#manual">Manual</a>

## 1. Our Project: Autonomous parking with Smartcar<a id="ourproject"></a>

<img align="right" src="https://media.giphy.com/media/KHcGe1SGuh6sI2tYgy/giphy.gif">

### What is our idea?

Our main idea for this project is a smartcar that is capable of autonomous parking in an empty spot when given a command to do so. We are directing our focus on **automatic parking functionality**, but will also see if there is enough time for additional functionalities to be implemented, namely - making manual controls for the car, autonomous parking specialization (for different cases).



### How are we going to do this?
Car will stay idle till it is interacted with. In order to relay the command to park, along with a few other commands (**Bluetooth commands** **start moving**, **stop**, **LED light blinking during certain maneuvers**, **manual controls** and **parking feature**), we are going to create **UI** for the car - a simple **mobile app** which uses bluetooth connection to communicate with the car. After receiving a command, smartcar will change its movement accordingly to correspond to it. Smartcar at the same time will include obstacle avoidance capabilities to **avoid collision** while on autonomous movement (i.e. detecting obstacles in front of it, behind it, as well as on the car's right side in order to park without hitting anything).

### Why?
Goal of this idea is intended for comfortability of the customer and efficiency in performing common everyday task with just a few buttons pressed on your smartphone. Autonomous parking aids safety purposes as well. We want to reduce the amount of accidents the cars are involved in and increase its obstacle detection in order to avoid obstacles in a smarter way.

### Components we are going to use:
  - Smartcar shield
  - Gyroscope
  - Speed encoders
  - Bluetooth platform
  - Ultrasonic sensors
  - LED light
  
### Contributors
- Adelric Wong
- Shab Pompeiano
- Stanko Jankovic
- Arvin Esfahani Zadeh Sakhi Langeroudi
- Martynas Lekeckas

### Product owners
- Ilja Pavlov
- M Nazeeh Alhosary

### Customer
- Dimitrios Platis

## 2. Installation<a id="installation"></a>

Follow these steps to install the product

**SmartCar**
1. *Download the latest version of Arduino IDE*
2. *Open the sketch Arduino_code/Arduino_code.ino*
3. *Connect the SmartCar*
4. *Compile the sketch and upload it to the SmartCar*

Now it's time to install the Android app

**Android Phone**
1. *Download the apk Project.apk on an Android phone*
2. *Install the apk*
3. *Find the application "Project" and open it*


## 3. Manual <a id="manual"></a>

1. Open the application, titled "Project"
2. Tap on Bluetooth button
3. Once Bluetooth is turned on, tap on connect to car
4. There are 3 Operational Options: Cruise Control, Manual Control and Parking
5. For cruise control, tap on it and the car will manoveur and avoid obstacles automatically
6. For manual control, there are 4 directional controls and a speed adjustment slider
7. [Manual Control]: Forward, Backward, Left and Right buttons moves the car accordingly when tapped
8. [Manual Control]: Speed adjustment slider allows you to drag and slide the cursor to change the car speed
9. For Parking, when tapped there is a button called "Park" which sends the car into a parallel 	parking mode
