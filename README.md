# group-08

### Content table
1. <a href="#1">Our Project</a>
   1. <a href="#1.1">What is our idea?</a>
   2. <a href="#1.2">How are we going to do this?</a>
   3. <a href="#1.3">Why?</a>
   4. <a href="#1.4">Customer</a>
   5. <a href="#1.5">Product Owner</a>
2. <a href="#2">Technical aspects</a>
   1. <a href="#2.1">Components we are going to use</a>
   2. <a href="#2.2">Softwares used and Development environment</a>
3. <a href="#3">Installation</a>
4. <a href="#4">Manual</a>
5. <a href="#5">Contributors</a>

## 1. Our Project: Autonomous parking with Smartcar <a id="1"></a>

<img align="right" src="https://media.giphy.com/media/KHcGe1SGuh6sI2tYgy/giphy.gif">

### 1.1 What is our idea? <a id="1.1"></a>

Our main idea for this project is a smartcar that is capable of autonomous parking in an empty spot when given a command to do so. We are directing our focus on **automatic parking functionality**, but will also see if there is enough time for additional functionalities to be implemented, namely - making manual controls for the car, autonomous parking specialization (for different cases).



### 1.2 How are we going to do this? <a id="1.2"></a>
Car will stay idle till it is interacted with. In order to relay the command to park, along with a few other commands (**Bluetooth commands** **start moving**, **stop**, **LED light blinking during certain maneuvers**, **manual controls** and **parking feature**), we are going to create **UI** for the car - a simple **mobile app** which uses bluetooth connection to communicate with the car. After receiving a command, smartcar will change its movement accordingly to correspond to it. Smartcar at the same time will include obstacle avoidance capabilities to **avoid collision** while on autonomous movement (i.e. detecting obstacles in front of it, behind it, as well as on the car's right side in order to park without hitting anything).

### 1.3 Why? <a id="1.3"></a>
Goal of this idea is intended for comfortability of the customer and efficiency in performing common everyday task with just a few buttons pressed on your smartphone. Autonomous parking aids safety purposes as well. We want to reduce the amount of accidents the cars are involved in and increase its obstacle detection in order to avoid obstacles in a smarter way.

### 1.4 Customer <a id="1.4"></a>
- Dimitrios Platis

### 1.5 Product owners <a id="1.5"></a>
- Ilja Pavlov
- M Nazeeh Alhosary

## 2. Technical aspects <a id="2"></a>

### 2.1 Components we are going to use <a id="2.1"></a>
  - **Smartcar shield**
  - **Arduino Mega 2560 REV3**
  - **Gyroscope GY-50 L3G4200**
  - **2x Speed encoders**
  - **Bluetooth Module HC-O6**
  - **3x Ultrasonic Sensor HC-SR04 **
  - **LED light**

The **Smartcar shield** is the core of the car, all the components are mounted on the shield, including the **Arduino Mega 2560 REV3** which is the "brain" of the Smartcar as the applicative that controls the car and all its connected components will run on this.
Three **Ultrasonic Sensors HC-SR04** are mounted accordingly in front, to the right and on the back of the car and used to detect obstacles. 
Moreover a **Bluetooth Module HC-06** is also connected to the car to make the car communicate with the Android app- and two **Speed encoders** measure the distance travelled by the car (one for each side of the car).
Finally there are a **LED light** and a **Gyroscope GY-50 L3G4200**

### 2.2 Softwares used and Development environment <a id="2.2"></a>
  - **Arduino IDE**
  - **Android Studio**

**Arduino IDE** has been used to develop and test the application that would run on the car.
**Android Studio** has been instead used to develop and test the application that would run on the android phone.



## 3. Installation <a id="3"></a>

Here you can find the steps to follow in order to try the app

**Setup the SmartCar**
1. *Download the latest version of Arduino IDE*
2. *Install the Smartcar shield library*
2. *Open the sketch Arduino_code/Arduino_code.ino*
3. *Connect the SmartCar*
4. *Compile the sketch and upload it to the SmartCar*

Now it's time to install the Android app

**Setup the Android Phone**
1. *Download the apk Project.apk on an Android phone*
2. *Install the apk*
3. *Find the application "Project" and open it*


## 4. Manual <a id="4"></a>

1. Open the application, titled "Project"
2. Tap on Bluetooth button
3. Once Bluetooth is turned on, tap on connect to car
4. There are 3 Operational Options: Cruise Control, Manual Control and Parking
5. For cruise control, tap on it and the car will manoveur and avoid obstacles automatically
6. For manual control, there are 4 directional controls and a speed adjustment slider
7. [Manual Control]: Forward, Backward, Left and Right buttons moves the car accordingly when tapped
8. [Manual Control]: Speed adjustment slider allows you to drag and slide the cursor to change the car speed
9. For Parking, when tapped there is a button called "Park" which sends the car into a parallel 	parking mode

## 5. Contributors <a id="5"></a>
- <a href="https://github.com/FrenzyRic">Adelric Wong</a>
- <a href="https://github.com/Shab98">Shab Pompeiano</a>
- <a href="https://github.com/7SJ7">Stanko Jankovic</a>
- <a href="https://github.com/The-R-Win">Arvin Esfahani Zadeh Sakhi Langeroudi</a>
- <a href="https://github.com/TheMartyLekekas">Martynas Lekeckas</a> 
