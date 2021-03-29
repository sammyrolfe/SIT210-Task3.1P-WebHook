// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT.h>
#include "Adafruit_DHT.h"

#define DHTTYPE DHT11
#define DHTPIN 2 


DHT dht(DHTPIN, DHTTYPE);

void setup() {
    
  	Serial.begin(9600); 
	dht.begin();
	
}

void loop() {


    // Read temperature as Celsius
	int t = dht.getTempCelcius();
    String temp = String(t);
    
    // Publish to webhook
    Particle.publish("temp", temp, PRIVATE);
    delay(1000);               // Wait for 30 seconds
    
}