# group-08

### Content table
1. <a href="#1">Our Project</a>
   + <a href="#1.1">What is our idea?</a>
   + <a href="#1.2">How are we going to do this?</a>
   + <a href="#1.3">Why?</a>
   + <a href="#1.4">Product Owner</a>
   + <a href="#1.5">Customer</a>
2. <a href="#2">Technical aspects</a>
   + <a href="#2.1">Components we are going to use</a>
   + <a href="#2.2">Softwares used and Development environment</a>
3. <a href="#3">Features</a>
   + <a href="#3.1">Obstacle avoidance</a>
   + <a href="#3.2">Bluetooth connection</a>
   + <a href="#3.3">Manual control</a>
   + <a href="#3.4">Autonomous driving</a>
   + <a href="#3.5">Automatic parallel parking</a>
   + <a href="#3.6">LED light</a>
4. <a href="#4">Installation</a>
   + <a href="#4.1">Setup the Smartcar</a>
   + <a href="#4.2">Setup the Android Phone</a>
5. <a href="#5">Manual</a>
6. <a href="#6">Contributors</a>

<br><br>
## <a id="1"></a>1. Our Project: Autonomous parking with Smartcar 

<a id="gif"></a><img align="right" src="https://media.giphy.com/media/KHcGe1SGuh6sI2tYgy/giphy.gif">

### <a id="1.1"></a>What is our idea? 

Our main idea for this project is a smartcar that is capable of autonomous parking in an empty spot when given a command to do so. We are directing our focus on **automatic parking functionality**, but will also see if there is enough time for additional functionalities to be implemented, namely - making manual controls for the car, autonomous parking specialization (for different cases).



### <a id="1.2"></a>How are we going to do this? 
Car will stay idle till it is interacted with. In order to relay the command to park, along with a few other commands (**Bluetooth commands** **start moving**, **stop**, **LED light blinking during certain maneuvers**, **manual controls** and **parking feature**), we are going to create **UI** for the car - a simple **mobile app** which uses bluetooth connection to communicate with the car. After receiving a command, smartcar will change its movement accordingly to correspond to it. Smartcar at the same time will include obstacle avoidance capabilities to **avoid collision** while on autonomous movement (i.e. detecting obstacles in front of it, behind it, as well as on the car's right side in order to park without hitting anything).

### <a id="1.3"></a>Why? 
Goal of this idea is intended for comfortability of the customer and efficiency in performing common everyday task with just a few buttons pressed on your smartphone. Autonomous parking aids safety purposes as well.<br>
We want to reduce the amount of accidents the cars are involved in and increase its obstacle detection in order to avoid obstacles in a smarter way.

### <a id="1.4"></a>Product owners 
- Ilja Pavlov
- M Nazeeh Alhosary

### <a id="1.5"></a>Customer
- Dimitrios Platis

<br><br>
## 2. <a id="2"></a>Technical aspects 

### <a id="2.1"></a>Components we are going to use 
  - **Smartcar shield**
  - **Arduino Mega 2560 REV3**
  - **Gyroscope GY-50 L3G4200**
  - **2x Speed encoders**
  - **Bluetooth Module HC-O6**
  - **3x Ultrasonic Sensor HC-SR04**
  - **LED light**

The **Smartcar shield** is the core of the car, all the components are mounted on the shield, including the **Arduino Mega 2560 REV3** which is the "brain" of the Smartcar as the applicative that controls the car and all its connected components will run on this.<br>
Three **Ultrasonic Sensors HC-SR04** are mounted accordingly in front, to the right and on the back of the car and used to detect obstacles.<br>
Moreover a **Bluetooth Module HC-06** is also connected to the car to make the car communicate with the Android app- and two **Speed encoders** measure the distance travelled by the car (one for each side of the car).<br>
Finally there are a **LED light** and a **Gyroscope GY-50 L3G4200**

### <a id="2.2"></a>Softwares used and Development environment
  - **Arduino IDE**
  - **Android Studio**

**Arduino IDE** has been used to develop and test the application that would run on the car.<br>**Android Studio** has been used to develop and test the application that would run on the android phone.

<br><br>
## 3. <a id="3"></a>Features

### <a id="3.1"></a>Obstacle avoidance
The Smartcar is able to detect obstacles using the Ultrasonic Sensors mounted on the front, on the right side and on the back of the car.

### <a id="3.2"></a>Bluetooth connection
The Smartcar can be connected to an android phone. From the Android app it is possible to turn on/off the bluetooth of the phone, see a list of discovered devices in the nearby and toggle the discoverability of the phone. 

### <a id="3.3"></a>Manual control
Through the Android app it is possible to manually control the Smartcar- the car is able to drive forward, backwards, forward turning left, forward turning right, backwards turning left and backwards turning right. The Smartcar is going to move as long as user is holding the button, as soon as the forward or backward button is released car stops.

### <a id="3.4"></a>Autonomous driving (Cruise control)
Through the Android app it is possible to activate the autonomous driving mode which will make the car drive until an obstacle is approached, then the car will turn right or left if there is an obstacle to the right side of the car too. Afterwards, the car will continue with the ride, until the user gives another command.

### <a id="3.5"></a>Automatic parallel parking
Through the Android app it is possible to start the parking manouvre that will park the car between two obstacles as the picture shows <a href="#gif">here</a>. 

### <a id="3.6"></a>LED light
A LED Light will blink to signal that the car is in motion. As soon as the car stops, a LED light will stop blinking and switch the state to stable ON. This feature works for all 3 modes (**Manual control, Autonomous driving (Cruise control), Automatic parallel parking**)

<br><br>
## 4. <a id="4"></a>Installation 

Here you can find the steps to follow in order to try the app.

Before starting you should clone our repository, if you have Git Bash open a terminal and type  
```git
git clone https://github.com/DIT112-V19/group-08.git
```
Otherwise download the repository from <a href="https://github.com/DIT112-V19/group-08/archive/master.zip">here.</a>

**Setup the Smartcar** <a id="4.1"></a>
1. *Download the latest version of <a href="https://www.arduino.cc/en/Main/Software">Arduino IDE</a>*
2. *Install the <a href="https://www.arduinolibraries.info/libraries/smartcar-shield">Smartcar shield library</a>*
2. *Open the sketch <a href="https://github.com/DIT112-V19/group-08/blob/master/Arduino_code/Arduino_code.ino">Arduino_code/Arduino_code.ino</a>*
3. *Connect the SmartCar*
4. *Compile the sketch and upload it to the SmartCar*

Now it's time to install the Android app:

**Setup the Android Phone** <a id="4.2"></a>
1. *Download the apk <a href="https://github.com/DIT112-V19/group-08/blob/master/Project.apk">Project.apk</a> on an Android phone*
2. *Install the apk*
3. *Find the application "Project" and open it*

<br><br>
## 5. <a id="5"></a>Manual 

1. Open the application, titled "Project"
2. Tap on Bluetooth button
3. Once Bluetooth is turned on, tap on connect to car
4. There are 3 Operational Options: Cruise Control, Manual Control and Parking
5. For cruise control, tap on it and the car will manoveur and avoid obstacles automatically
6. For manual control, there are 4 directional controls and a speed adjustment slider
7. [Manual Control]: Forward, Backward, Left and Right buttons moves the car accordingly when tapped (it is possible to hold pressed two adjacent buttons)
8. [Manual Control]: Speed adjustment slider allows you to drag and slide the cursor to change the car speed
9. For Parking, when tapped there is a button called "Park" which sends the car into a parallel 	parking mode

<br><br>
## 6. <a id="6"></a>Contributors 
- <a href="https://github.com/FrenzyRic"> <img src="https://avatars3.githubusercontent.com/u/43994809?s=460&v=4" width="17" height="17"> Adelric Wong</a>
- <a href="https://github.com/Shab98"> <img src="https://avatars2.githubusercontent.com/u/45070337?s=460&v=4" width="17" height="17"> Shab Pompeiano</a>
- <a href="https://github.com/7SJ7"> <img src="https://avatars1.githubusercontent.com/u/44894294?s=460&v=4" width="17" height="17"> Stanko Jankovic</a>
- <a href="https://github.com/The-R-Win"> <img src="https://avatars3.githubusercontent.com/u/43420832?s=460&v=4" width="17" height="17"> Arvin Esfahani Zadeh Sakhi Langeroudi</a>
- <a href="https://github.com/TheMartyLekekas"> <img src="https://avatars2.githubusercontent.com/u/43269722?s=460&v=4" width="17" height="17"> Martynas Lekeckas</a> 
