#include <Arduino.h>
#include <CredentialsManager_BK.h>

CMBK Manager;
WiFiClient WiFi_client;
PubSubClient MQTT_client(WiFi_client);



void setup()
{
  #ifdef Serial_Debug 
    Serial.begin(115200);
    Serial.println("Booted");
  #endif
  delay(1000);

  if (touchRead(12) < 40) {
    #ifdef Serial_Debug
        Serial.println("TouchPad while uC start! Start Server");
    #endif
    Manager.begin();
  }
  
  if (Manager.readData()) {
    bool StartServer        = false;

    const char* ctrlname    = Manager.Credentials["NAME"];
    const char* ssid        = Manager.Credentials["WIFI_SSID"];
    const char* pw          = Manager.Credentials["WIFI_PW"];
    const char* mqttip      = Manager.Credentials["MQTT_IP"];
    const uint16_t mqttport = Manager.Credentials["MQTT_PORT"];
    const char* mqttid      = Manager.Credentials["MQTT_ID"];
    const char* mqttpw      = Manager.Credentials["MQTT_PW"];
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pw);
    unsigned long StartTime = millis();

    //  to connect
    while ((WiFi.status() != WL_CONNECTED) && !StartServer) {
      if ((WiFi.status() == WL_NO_SSID_AVAIL)
      ||  (WiFi.status() == WL_CONNECT_FAILED)) {
        #ifdef Serial_Debug
            Serial.println("Wrong Credentials! Start Server");
        #endif
        StartServer = true;
      }
      if ((millis()-StartTime) > 15000)
      {
        #ifdef Serial_Debug
            Serial.println("Connection Failed! Start Server");
        #endif
        StartServer = true;
      }
    }
    if (!StartServer) {
            
      MQTT_client.setServer(mqttip, mqttport);

      uint8_t retries   = 1;
      while (!MQTT_client.connected() && !StartServer) {
          // Attempt to connect
          if (MQTT_client.connect(ctrlname,mqttid,mqttpw,0,1,0,0,1)) {
            #ifdef Serial_Debug
              Serial.println("connected");
            #endif
          } else {
            #ifdef Serial_Debug
              Serial.print("failed, rc=");
              Serial.print(MQTT_client.state());
            #endif
            retries++;
          }

          if (retries > 3)
          {
            #ifdef Serial_Debug
              Serial.println("Can not connect to mqtt broker!");
            #endif
            StartServer          = true;
          }
      }
    }

    if (StartServer)
    {
      Manager.begin();
    }
    
  }
}

void loop()
{
  if (touchRead(12) < 40)
  {
    #ifdef Serial_Debug
      Serial.println("Touch!");
    #endif
  }
}