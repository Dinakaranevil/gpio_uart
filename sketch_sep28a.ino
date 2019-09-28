byte transmit = 7; //define our transmit pin
byte data = 170; //value to transmit, binary 10101010
byte mask = 1; //our bitmask
byte bitDelay = 100;

void setup() {
  Serial.begin(9600);
   pinMode(transmit,OUTPUT);//open the serial port at 9600 bps:
}
 char rx_byte = 0;

void loop() {
  // print labels

  if (Serial.available() > 0)
  {    // is a character available?
    rx_byte = Serial.read(); 
    
  
  for (mask = 00000001; mask>0; mask <<= 1) { //iterate through bit mask
    if (rx_byte & mask)
    { // if bitwise AND resolves to true
      digitalWrite(transmit,HIGH); 
      Serial.print("1");// send 1
    }
    else
    { //if bitwise and resolves to false
      digitalWrite(transmit,LOW);
      Serial.print("0");// send 0
    }
    delayMicroseconds(bitDelay); //delay
  }
  }
 
  // prints a label        // prints a tab
}
