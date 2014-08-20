/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // make the pushbutton's pin an input:
  pinMode(A0,INPUT);
  pinMode(pin5, INPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, INPUT);
}

float averageAnalogRead;
int counter=0;
// the loop routine runs over and over again forever:
void loop() {
  float current = analogRead(A0);
  float newAverage = averageAnalogRead * counter + current;
  counter++;
  averageAnalogRead = newAverage;
  
  if (counter > 2^31){
   averageAnalogRead=current;
   counter=0;
  } 
}

void serialEvent(){
  //statements

  char command = Serial.read();
  // because there are only these three pins being used. they are used with pullups
    switch (command) {
      case '0':
      Serial.println(analogRead(A0));
      break;
    case '5':
      Serial.println(digitalRead(pin5));
        break;
    case '6':
      //do something when var equals 2
      Serial.println(digitalRead(pin6));
        break;
    case '7':
       // do something
       Serial.println(digitalRead(pin7));
        break; 
    default: 
       Serial.println("-1");
      break;
  }

}



