IPAddress apIP(192,168,1,1);

String _ssid = "DIR-825-993D";
String _password = "90170102";
String _ssidAP = "WifiHome";
String _passwordAP = "11111111";

void WiFiInit()
{  
  WiFi.mode(WIFI_STA);
  byte tries = 11;
  WiFi.begin(_ssid, _password);
  while(--tries&& WiFi.status()!= WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);    
  }  
  Serial.println("");
  if(WiFi.status()!= WL_CONNECTED)
  {
    Serial.println("WiFi up AP");
    if(StartAPMode()) Serial.println(WiFi.softAPIP());
  }
  else
  {
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());    
  }  
}

bool StartAPMode()
{
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP,apIP,IPAddress(255,255,255,0));
  WiFi.softAP(_ssidAP, _passwordAP);
  return true;
}
