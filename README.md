# Laser-Defense-System 🎇

Pew Pew!!!

This is meant to be a fun little harmless project for those who enjoy interactive gadgets, get easily distracted, or need a fun little tool to keep their pets entertained. Our Laser Defense System offers an immersive experience, allowing users to control a laser beam in real-time through the use of two modes: manual and auto-sensing mode.

## Dependencies 
- Arduino IDE (Preferbaly Version 2.3.3)
- Git (Optional)

## How to Set up the Project 
To get started clone this repo or download the zip file and extract it on your local machine. To clone using git type the following command 
```$ git clone https://github.com/imtooMilly/Laser-Defense-System.git ```

After cloning the repo, open up the project in the Arduino IDE and connect the Arduino to its IDE via a serial port. In addition, open up the Serial Monitor tool in the IDE. To open up the tool you have the following options:
- Go under Tools -> Serial Monitor
- Hit the CTRL + SHIFT + M keys on your keyboard

## Interacting with the Project 
Once you finish setting up, the structure of your project should look something like this:

```
.
├── Laser Defense System
│   └── LDS_Sketch
│       └── LDS_Sketch.ino  Main sketch file                
│   └── Testing             Test Files for sketches 
│   └── README.md           Project README file 
```
Once you connect the Arduino to the IDE the Laser Defense system will automatically start up and launch in _Manual Sensing Mode_. The Serial Monitor tool will show the following text 
``` Mode: Joystick ```. 

To switch between manual and auto-sensing modes, click on the button located on the breadbox:


## Manual Sensing Mode 🕹

In manual sensing mode, the user is in full control. By using the joystick, the laser beam’s orientation will change accordingly. In addition, the laser can be toggled on/off if the joystick button is pressed.  
This allows users to have a hands-on experience that they will never forget. Every action and input is deliberate and impactful, making those inner mad scientist dreams come to fruition. 

## Auto Sensing Mode 🤖

For those who don’t need that kind of control and want a more relaxing experience, the auto-sensing mode provides that as it does the work for you. Its built-in sensors will scan the environment and find suitable targets to shoot its beam. If the sensors detect an object _15cm_ away the laser will turn on, atomizing everything in its path. However, if the sensors can't detect anything the laser will be inactive. In a way, everything is automatic and seamless leaving no room for user intervention. If you are ever bored or can’t entertain your pet then this is the mode for you.


## To Conclude 🏁
Overall, this project is meant to entertain you, the user with a little touch of software development and engineering. We hope you have fun interacting with this piece of technology!

