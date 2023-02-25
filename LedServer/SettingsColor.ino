void setBright(byte brightness)
{
  strip.setBrightness(brightness);  
  SetMode(saveMode);
}

void setHue(byte color)
{
  for (int i = 0; i < LED_NUM; i++) 
  {
    strip.setPixelColor(i ,Adafruit_NeoPixel::ColorHSV( color *255,255, 255)); 
  }      
  strip.show();  
}  
void setRGB(byte R, byte G, byte B)
{ 
  strip.fill((R*256 +G)*256 + B,0,LED_NUM);     
  strip.show();  
}
