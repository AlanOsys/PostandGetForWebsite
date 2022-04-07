
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <SPI.h>
#include <Adafruit_GFX.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#define OLED_RESET -1

#include <Wire.h>
#include <Servo.h>
Servo myservo;
int pos = 0;



const char* ssid = "WifiSSID";
const char* password = "Password";

void setup() {
  
  myservo.attach(D4);
  Serial.begin(9600); // Start the serial monitor.
  delay(10); // Give it a moment.

  

  // Connect to WiFi network:
  Serial.println("Hello Digital Craft");
  Serial.println("Connecting "); 
  WiFi.begin(ssid, password);

  // Show ... until connected:
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");

  // Print the IP address of the device:
  Serial.println(WiFi.localIP());
  

}

void loop() {
 
  
  
   // Verfiy WiFi is connected:
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;  // Object of the class HTTPClient.

    http.begin("http://alanosys.online/data.txt");  // Request destination.
    int httpCode = http.GET(); // Send the request.

    if (httpCode > 0) { //Check the returning code

      Serial.println("We got a repsonse!");
      String payload = http.getString();   // Get the text from the destination (1 or 0).
      if(payload == "0"){
        myservo.write(0);
      }
      else{
        myservo.write(60);
      }
        
      
    }else{

      Serial.println("Something baaaaaaad happened!");

    }

    http.end();   //Close connection

  }

  delay(1000);    //Send a request every 30 seconds

  
}
