/*------------------------------------------------------------------------------------------
This Project uses an existing garage door opener and connects directly to the switch to be 
pressed by the user. The ESP8266 gets the input from the Blynk app and translates it 
into the relay to open or close the garage door.
------------------------------------------------------------------------------------------*/

/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial
#define Button 4
#define LED 5
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = ""; //Blynk project auth code
char ssid[] = "";                           // My WIFI network name
char pass[] = "";                      // My WIFI network password

/* This function reads the input from virtual input in the Blynk app and writes it to a variable here*/
BLYNK_WRITE(V1)
{
  int up = param.asInt(); // assigning incoming value from pin V1 to a variable

  if (up==1)
  {
    digitalWrite(Button, HIGH);
    digitalWrite(LED, HIGH);
  }
  else
  {
  digitalWrite(Button, LOW);
  digitalWrite(LED, LOW);
  }
}
void setup()
{
  Blynk.begin(auth, ssid, pass);

  pinMode(Button, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  Blynk.run();
}
