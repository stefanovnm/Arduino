/***************************************************
 This example reads Capacitive Soil Moisture Sensor.
 
 Created 2015-10-21
 By berinie Chen <bernie.chen@dfrobot.com>
 
 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here: https://www.dfrobot.com/wiki/index.php?title=Capacitive_Soil_Moisture_Sensor_SKU:SEN0193
 2.This code is tested on Arduino Uno.
 3.Sensor is connect to Analog 0 port.
 ****************************************************/

const int AirValue = 600;   //you need to replace this value with Value_1
const int WaterValue = 280;  //you need to replace this value with Value_2
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
else if(soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals))
{
  Serial.println("Wet");
}
else if(soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals))
{
  Serial.println("Dry");
}
Serial.println(soilMoistureValue);


  if (soilMoistureValue >= 500){
    digitalWrite(pinOut, HIGH);
    delay(5000);
  }
  else {
    digitalWrite(pinOut, LOW);
  }
  

delay(3000);
}
