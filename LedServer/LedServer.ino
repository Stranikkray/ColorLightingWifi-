#include "Adafruit_NeoPixel.h" //https://adafruit.github.io/Adafruit_NeoPixel/html/class_adafruit___neo_pixel.html
#include <ESP8266WiFi.h>


#define LED_PIN D2     // пин
#define LED_NUM 97    // количество светодиодов
#define SizeBytes 2

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

WiFiServer server(2005);
WiFiClient client;

byte saveMode[SizeBytes];

void setup() {
  strip.begin();
  strip.setBrightness(50);
  Serial.begin(115200);
  WiFiInit();
  server.begin();
}

void loop() 
{
  byte data[SizeBytes];
  int ind=0;
  if(!client.connected())
  {
    client = server.available();
  }
  else
  {
    if(client.available()>0)
    {
      while(client.available())
      {
        data[ind++] = client.read();
      }
      client.flush();
      Serial.print(data[0]);
      Serial.print(" ");
      Serial.println(data[1]);
      SetMode(data);          
    }
  }  
}

void SetMode(byte selection[])
{
  switch(selection[0])
  {
    case 0:
    {    
      setBright(selection[1]);
      return;
    }    
    case 1:
    {
      setHue(selection[1]);       
      break; 
    }     
    default:
    {
      Serial.println("Method not found");
      break;
    }    
  }
  for(int i = 0; i < SizeBytes;i++)
  {
      saveMode[i] = selection[i];
  }    
}
