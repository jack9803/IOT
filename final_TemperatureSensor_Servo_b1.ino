#include <Servo.h>
#include "LDHT.h"

LDHT dht(2,DHT22);
Servo myservo;
int starting=0;
float tempC=0.0,Humi=0.0;

void setup() {
  Serial.begin(9600);
  myservo.attach(3);
  myservo.write(0);

  dht.begin();
  Serial.print(DHT22);
  Serial.println(" test!");
}

void loop() {
    /*for(int i=0; i<90; i++){
      myservo.write(i);
      delay(15);  
    }
      for(int i=90; i>=0; i--){
      myservo.write(i);
      delay(15);  
    }*/
  
  
  
  if(dht.read())
    {
        tempC = dht.readTemperature();
        Humi = dht.readHumidity();

        Serial.println("------------------------------");
        Serial.print("Temperature Celcius = ");
        Serial.print(dht.readTemperature());
        Serial.println("C");

        Serial.print("Temperature Fahrenheit = ");
        Serial.print(dht.readTemperature(false));
        Serial.println("F");

    }
	  if((tempC>29)&&starting==0){
		for(int i=0; i<90; i++){
		  myservo.write(i);
		  delay(10);  
		}
		  for(int i=90; i>=0; i--){
		  myservo.write(i);
		  delay(10);  
		}
		starting=1;
	  }else if(tempC<26&&starting==1){
		  for(int i=0; i<90; i++){
			  myservo.write(i);
			  delay(10);  
			}
			  for(int i=90; i>=0; i--){
			  myservo.write(i);
			  delay(10);  
			}
		starting=0;
	  }

   delay(100);
}
