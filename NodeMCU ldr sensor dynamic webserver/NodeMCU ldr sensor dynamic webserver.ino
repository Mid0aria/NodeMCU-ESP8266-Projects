#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"  //Web page header file - MAIN_page

ESP8266WebServer server(80); //Server on port 80

//Enter your WiFi SSID and PASSWORD
const char* ssid = "SSID";
const char* password = "PASSWORD";
const int ledPin = 5; // D1
const int ldrPin = A0;

void handleRoot() {
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}
 
void handleLDR() {
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <= 50) {

    digitalWrite(ledPin, HIGH);
    Serial.print(ldrStatus);
    Serial.print("LED is ON");
    Serial.println("");
    delay(1000);
  }

  else {
    Serial.print(ldrStatus);
    digitalWrite(ledPin, LOW);
    Serial.println("LED is OFF");
    Serial.println("");
    delay(1000);
 //int a = analogRead(A0);
 String ldrValue = String(ldrStatus);
 
 server.send(200, "text/plane", ldrValue); //Send ADC value only to client ajax request
}
}


void setup(void){
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA); //Connect wifi
  WiFi.begin(ssid, password); // wifi credentials

  Serial.println("Connecting to ");
  Serial.print(ssid);

  //Wait for WiFi to connect
  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
  }
    
// If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
//----------------------------------------------------------------
 
  server.on("/", handleRoot);      //This is display page
  server.on("/readLDR", handleLDR); //To get update of ADC Value only
 
  server.begin();   //Start client
  Serial.println("WebClient started");

  pinMode(ledPin, OUTPUT);

  pinMode(ldrPin, INPUT);
}

void loop(void){
  server.handleClient();
  delay(1);
}