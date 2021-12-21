One Solution to setup new iot devices. Using Web Server to help user easily type in wifi and mqtt credentials.

The following things are required:
1. Platform IO or Arduino IDE
2. ESP32
3. MQTT Broker

Instruction:

1. Choose COM port (PlatformIO)
![Choose Port](https://user-images.githubusercontent.com/40664333/147005724-3a9f90e1-ea31-4aa9-9088-bf9f07b5895e.png)

2. Upload Filesyste Image to the ESP32 SPIFFS (PlatformIO)
![Upload Filesystem Image via PlatformIO](https://user-images.githubusercontent.com/40664333/147004814-355e7655-10b0-4e65-a7bd-24b3f014bfc8.png)

Terminal Output:
![Upload Filesystem Image via PlatformIO_Terminal done](https://user-images.githubusercontent.com/40664333/147004979-3646cdec-2bb1-423d-8c5d-6ba349d91b6b.png)

3. Upload Program to ESP32 (PlatformIO)

Terminal Output:
![Upload Program PlatformIO_Terminal done](https://user-images.githubusercontent.com/40664333/147005298-2cdd9f6c-e03c-4f6f-a1c7-340460e6de78.png)

4. Start Serial Monitor and wait for WebServer and IP
![Serial Monitor](https://user-images.githubusercontent.com/40664333/147005994-7a9c128e-d7c3-4c02-9a28-fcdfc908eb76.png)

5. Login to AP.
![LogIn AP](https://user-images.githubusercontent.com/40664333/147006671-38b09bde-6cb2-4939-ab33-449bcf126388.png)

6. Open Browser. Type in IP shown in Serial Monitor. Submit Inputs and wait for result.
![WebServer](https://user-images.githubusercontent.com/40664333/147006700-4ded31d0-1fd0-4d6d-98a5-36d0b026c212.png)

Success:
![WebServer_success](https://user-images.githubusercontent.com/40664333/147006792-8dc3b716-7af5-4eb5-b7b2-461f60b05071.png)

After success, esp will restart after 5s.
