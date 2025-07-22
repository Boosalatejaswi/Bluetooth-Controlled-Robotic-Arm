Code:
hashtag#include <Servo.h>
Servo servo1; // Base rotation
Servo servo2; // Arm movement
Servo servo3; // Claw movement
int servo1Pos = 90; // Initial positions
int servo2Pos = 90;
int servo3Pos = 90;

char command; 
void setup() {
 Serial.begin(9600); 
 servo1.attach(9); 
 servo2.attach(10); 
 servo3.attach(11); 
 servo1.write(servo1Pos);
 servo2.write(servo2Pos);
 servo3.write(servo3Pos);
}

void loop() {
 if (Serial.available()) { // Check if data is received
 command = Serial.read(); // Read the command
 Serial.println(command); // Print received command

 switch (command) {
 case 'A': servo1Pos += 10; break; // Rotate left
 case 'D': servo1Pos -= 10; break; // Rotate right
 case 'W': servo2Pos += 10; break; // Move arm up
 case 'S': servo2Pos -= 10; break; 
 case 'O': servo3Pos += 10; break; 
 case 'C': servo3Pos -= 10; break; 
 }
 servo1Pos = constrain(servo1Pos, 0, 180);
 servo2Pos = constrain(servo2Pos, 0, 180);
 servo3Pos = constrain(servo3Pos, 0, 180)!
 servo1.write(servo1Pos);
 servo2.write(servo2Pos);
 servo3.write(servo3Pos);
 }
}
