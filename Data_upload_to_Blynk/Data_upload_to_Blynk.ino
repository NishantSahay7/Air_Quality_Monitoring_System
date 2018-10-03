#include <ESP8266WiFi.h>              //Including the ESP8266 WiFi library in order to usm them

#include <BlynkSimpleEsp8266.h>       //library for linking up Blynk with ESP8266
#define BLYNK_PRINT Serial

#define Sensor A0                  //Defining the pin A0 for the Gas Sensor analog output
int Sensor_value=0;                     //variable to store RainDrop Sensor Module's output value

char auth[] = "auth-key";  //Authentication Key will be there in the Blynk App

char ssid[] = "ssid"; //SSID of the WiFi hotspot available
char pass[] = "password";  //Password of the WiFi

BlynkTimer timer;

void setup()
{
  
          Serial.begin(9600); //Initializing the Serial Monitor with a Baud Rate of 9600
        
          Blynk.begin(auth, ssid, pass);
          timer.setInterval(1000L, sendSensor);
         
}

void loop()
{

              Blynk.run();
              timer.run();
}


void sendSensor()       
{

            Sensor_value = analogRead(Sensor);
            Blynk.virtualWrite(V0, Sensor_value);
}


