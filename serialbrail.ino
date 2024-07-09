#include <Wire.h>
#include "PCA9685.h"

char serialData;

PCA9685 driver;

// PCA9685 outputs = 12-bit = 4096 steps
// 2.5% of 20ms = 0.5ms ; 12.5% of 20ms = 2.5ms
// 2.5% of 4096 = 102 steps; 12.5% of 4096 = 512 steps

PCA9685_ServoEvaluator pwmServo1(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo2(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo3(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo4(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo5(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo6(102, 512); // (-90deg, +90deg)

PCA9685_ServoEvaluator pwmServo7(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo8(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo9(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo10(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo11(102, 512); // (-90deg, +90deg)
PCA9685_ServoEvaluator pwmServo12(102, 512); // (-90deg, +90deg)

int down = 70;
int up = 35;

void setup() {
  
  Serial.begin(9600);
  Wire.begin();                 // Wire must be started first
  Wire.setClock(400000);        // Supported baud rates are 100kHz, 400kHz, and 1000kHz
  driver.resetDevices();        // Software redowns all PCA9685 devices on Wire line
  driver.init(B000000);         // Address pins A5-A0 down to B000000
  driver.setPWMFrequency(50);   // down frequency to 50Hz

  driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
  driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
  driver.setChannelPWM(2, pwmServo3.pwmForAngle(down));
  driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
  driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
  driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));

  driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
  driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
  driver.setChannelPWM(10, pwmServo9.pwmForAngle(down));
  driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
  driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
  driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
  
}


void loop() 
{
  if (Serial.available() > 0)
  {
    serialData = Serial.read();
    
    if(serialData == 'A' || serialData == 'a')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));                            /***** A *****/
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'B' || serialData == 'b')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));                           /***** B *****/
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
        
    }
    
    if(serialData == 'C' || serialData == 'c')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'D' || serialData == 'd')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'E' || serialData == 'e')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'F' || serialData == 'f')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'G' || serialData == 'g')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'H' || serialData == 'h')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'I' || serialData == 'i')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(down));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'J' || serialData == 'j')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(down));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'K' || serialData == 'k')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'L' || serialData == 'l')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'M' || serialData == 'm')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'N' || serialData == 'n')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'O' || serialData == 'o')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'P' || serialData == 'p')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'Q' || serialData == 'q')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'R' || serialData == 'r')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'S' || serialData == 's')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(down));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'T' || serialData == 't')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(down));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(down));
       
    }
    
    if(serialData == 'U' || serialData == 'u')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(up));
       
    }
    
    if(serialData == 'V' || serialData == 'v')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(up));
       
    }
    
    if(serialData == 'W' || serialData == 'w')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(down));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(up));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(down));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(up));
       
    }
    
    if(serialData == 'X' || serialData == 'x')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(down));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(up));
       
    }
    
    if(serialData == 'Y' || serialData == 'y')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(up));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(up));
       
    }
    if(serialData == 'Z' || serialData == 'z')
    {
      driver.setChannelPWM(0, pwmServo1.pwmForAngle(up));
      driver.setChannelPWM(1, pwmServo2.pwmForAngle(down));
      driver.setChannelPWM(2, pwmServo3.pwmForAngle(up));
      driver.setChannelPWM(4, pwmServo4.pwmForAngle(down));
      driver.setChannelPWM(5, pwmServo5.pwmForAngle(up));
      driver.setChannelPWM(6, pwmServo6.pwmForAngle(up));
       
    }










    serialData = Serial.read();
    
    if(serialData == 'A' || serialData == 'a')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));                            /***** A *****/
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'B' || serialData == 'b')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));                           /***** B *****/
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
        
    }
    
    if(serialData == 'C' || serialData == 'c')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'D' || serialData == 'd')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'E' || serialData == 'e')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'F' || serialData == 'f')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'G' || serialData == 'g')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'H' || serialData == 'h')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'I' || serialData == 'i')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(down));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'J' || serialData == 'j')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(down));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'K' || serialData == 'k')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'L' || serialData == 'l')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'M' || serialData == 'm')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'N' || serialData == 'n')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'O' || serialData == 'o')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'P' || serialData == 'p')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'Q' || serialData == 'q')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'R' || serialData == 'r')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'S' || serialData == 's')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(down));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'T' || serialData == 't')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(down));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(down));
       
    }
    
    if(serialData == 'U' || serialData == 'u')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(up));
       
    }
    
    if(serialData == 'V' || serialData == 'v')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(up));
       
    }
    
    if(serialData == 'W' || serialData == 'w')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(down));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(up));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(down));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(up));
       
    }
    
    if(serialData == 'X' || serialData == 'x')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(down));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(up));
       
    }
    
    if(serialData == 'Y' || serialData == 'y')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(up));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(up));
       
    }
    if(serialData == 'Z' || serialData == 'z')
    {
      driver.setChannelPWM(8, pwmServo7.pwmForAngle(up));
      driver.setChannelPWM(9, pwmServo8.pwmForAngle(down));
      driver.setChannelPWM(10, pwmServo9.pwmForAngle(up));
      driver.setChannelPWM(12, pwmServo10.pwmForAngle(down));
      driver.setChannelPWM(13, pwmServo11.pwmForAngle(up));
      driver.setChannelPWM(14, pwmServo12.pwmForAngle(up));
       
    }
  }
 }
