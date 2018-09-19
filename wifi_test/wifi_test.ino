/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "8c6c8575ab504465b09c6efce800de3e";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Vova";
char pass[] = "0987654321";

BLYNK_WRITE_DEFAULT() {
  Serial.print("input V");
  Serial.print(request.pin);
  Serial.println(":");
  // Print all parameter values
  for (auto i = param.begin(); i < param.end(); ++i) {
//    Serial.print("* ");
//    Serial.println(i.asString());
int spead = (i.asInt()- 512) * 2;
    if(request.pin==0){
       Serial.print("* ********************************************");
       if(spead >= 0){
       digitalWrite(D6, LOW);
       delay(10);
       analogWrite(D4, spead);
       
       }
       else{
       digitalWrite(D6, HIGH);
       delay(10);
       analogWrite(D4, spead * (-1));
       
       }
    
    }
    if(request.pin==1){
       Serial.print("* ********************************************");
       if(spead >= 0){
       digitalWrite(D5, LOW);
       delay(10);
       analogWrite(D3, spead);
       
       }
       else{
       digitalWrite(D5, HIGH);
       delay(10);
       analogWrite(D3, spead * (-1));
       
       }
    
    }

      
    }
  }
void setup()
{
  // Debug console
  Serial.begin(9600);

//  Blynk.begin(auth, ssid, pass);
  pinMode(LED_BUILTIN, OUTPUT);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  Blynk.begin(auth, ssid, pass, IPAddress(192,168,43,1), 8080);
}

void loop()
{
  Blynk.run();
}
