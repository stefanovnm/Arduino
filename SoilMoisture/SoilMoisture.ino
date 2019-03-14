/***********Notice and Trouble shooting***************
 1.This code is tested on Arduino Uno.
 2.Sensor is connect to Analog 0 port. Sensor is connected to 3.3V and GND //Capacitive soil moisture sensor
 3.Relay is connected to Digital 8 port. Raly is connected to 5V and GND  //JQC-3FF-S-Z
 ****************************************************/

const int AirValue = 600;
const int WaterValue = 285;
int intervals = (AirValue - WaterValue)/3;   //(600-285)/3=105
int soilMoistureValue = 0;
int pinOut = 8;

void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  pinMode(8, OUTPUT);
}
void loop() {
soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
if(soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals)) //moisture > 285 & moisture < 390
{
  Serial.println("Very Wet");
}
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals)) //moisture > 390 & moisture < 495
{
  Serial.println("Wet");
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals)) //moisture > 495 & moisture < 600
{
  Serial.println("Dry");
}
Serial.println(soilMoistureValue);


  if (soilMoistureValue >= 520){
    digitalWrite(pinOut, HIGH);
    delay(5000);
  }
  else {
    digitalWrite(pinOut, LOW);
  }
  

delay(3000);
}
