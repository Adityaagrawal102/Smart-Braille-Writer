# Smart-Braille-Writer
**INTRODUCTION:-
**Communication is very important in our day to day life. It is the process by which two or more people exchange ideas, facts, feelings, or impressions in ways that each gains a common understanding of the meaning, intent, and use of message. Also it is an integral quality as a human being and an important medium to share our emotions and thoughts with others. To mix up with the world, communication helps in exchanging thoughts, feelings, opinions and much more. Communication serves as a basic need to get recognized in a group and a crucial activity to stay close to one’s community [1]. To sound fair, communication is one of the fundamental rights of a person. However, the physically disabled people like blind, deaf, or dumb face a major challenge to have an effortless dialogue exchange with the present world [2]. Lack of communication leads to loneliness which can separate the physically disabled person from the society [3]. It also lowers the human self-respect which further may lead to taking up wrong decision or push the disabled person in depression. From recent years Braille has lowered the problem of physically impaired people [4]. Braille language consists of several rectangular blocks called cells that have tiny bumps called raised dots. There are 6 dots in each cell. The number and arrangement of these raised dots distinguish one character from another. A fixed pattern in which the dots are raised, represent the particular English alphabets. Braille considers the tactile sensation felt by the user through the embossing or other raised forms [5]. It is a script or a writing system which uses the virtue of the physical touch of the patterns representing the alphabets, punctuations and other necessities in our normal language. By moving the hand over the cell can make the disabled person feel the pattern of dots raised and further correlating it with the required alphabets will make him or her recognize it. This project takes the input in several forms as per the need and ability of the person. Further, this input is converted into the Braille language through the Python coding and servo motor mechanism. This device can be used by large number of people like blind, deaf, dumb, blind-deaf, deaf-dumb, blind-dumb and blind-deaf-dumb to convey and raise their voice in the world as well as to communicate with others including the underprivileged people of the society.

**MATERIALS**

Arduino UNO (Arduino, Italy), PCA 9685 (Adafruit, New York city), PLA filament (wanho solutions, China), Python IDLE (python, Online Community), Fusion 360 Designing software (Autodesk, USA), Cura (Autodesk, USA), Anaconda prompt (Terminal), The specification of laptop which was used during the making of device is Intel® Pentium® CPU 3700 @ 1.60Ghz.

**METHODOLOGY**

A virtual design was made at the initial stage with proper dimensions and exact mechanism. Later the components of the design were 3D printed. A proper dot raising mechanism was designed which is reliable and in a smooth working status. The components were then assembled as per the design made. 12 servo motors were connected to Arduino UNO via PCA9685. Python is used as a base language to give instructions to the device so that is can perform task on itself. To communicate between Python and Arduino a PySerial library was used [6]. It uses the serial monitor of Arduino to send and receive the data.   


A.	Making of Virtual Design
The design was made with proper dimensions and exact mechanism as shown in Fig 1. The software used to accomplish the virtual design is Autodesk fusion 360 [7]. Further the components in the design were 3D printed by using PLA filament (Fig 2 and Fig 3) as printing material.

<img width="319" alt="Screenshot 2024-07-09 at 7 46 18 PM" src="https://github.com/Adityaagrawal102/Smart-Braille-Writer/assets/143272577/f94bad58-31e9-4a3e-8e97-381117fd9f98">
Fig. 1  Virtual 3D design


 

Fig. 2  3D printed base


 

Fig. 3  3D printed elevation impression board



B.	Reliable Dot Raising Mechanism
A proper dot raising mechanism which can be reliable and in a smooth working status was designed (Fig 4). Paper clips were used to lift the dot through servo motor hub. By making servo motor rotate between 0 and 90 degrees, we were able to raise the particular dot.


 

Fig. 4  Dot raising mechanism


C.	Assembling all the components
All the 3D printed components were assembled according to the design also the paper clips were attached to each servo motor for dot raising mechanism (fig. 5). Each servo motor was attached to the Arduino UNO via PCA9685 (Fig. 6)[8].


 

Fig. 5  System assembly



 

Fig. 6   Servo motor connection
   
D.	Programming
Later on, our device needed some instructions to do task on itself. We used Python as the base language for programming.  Python libraries such PyAudio and Speech recognition were used to convert the input in the form of speech to Braille language. Also, in addition PyTesseract library was used to convert the given text into Braille Language[9]. The device is programmed according to the Optical Character Recognition (OCR) technology. Anaconda prompt was used as a terminal in the device.
IV.	APPLICATION

BLIND	DEAF	DUMB	NORMAL
TO
IMPAIRED	IMPAIRED
TO
NORMAL
YES	NO	NO	Direct	Direct
NO	YES	NO	Speech to sign language	Direct
NO	NO	YES	Direct	Sign language to speech / text
YES	YES	NO	Speech to braille	Direct
YES	NO	YES	Direct	Sign language to speech / text
NO	YES	YES	Speech to sign language	Sign language to speech / text
YES	YES	YES	Speech to braille	Sign language to speech / text


V.	RESULT
The aim of the project was to have a hurdle less and an efficient conversation between the physically impaired person and the normal person which we achieved as we had deduced it to be. 
Speech to Braille language
Whenever we speak any word in front of the device it converts it into braille language (fig. 7). For doing this it uses PyAudio python library[10]. A continues internet connection is required for achieving the desired result.

 

Fig. 7  Speech to Braille Language
Text to Braille language
Whenever we show any text to the camera (which is attached to the device), the text is converted into braille language (Fig. 8). The device uses Optical Character Recognition (OCR) technology to achieve above result.

 

Fig. 8  Text to Braille language
![image](https://github.com/Adityaagrawal102/Smart-Braille-Writer/assets/143272577/e66030dd-51d0-40ca-bf08-4691ce193bce)
