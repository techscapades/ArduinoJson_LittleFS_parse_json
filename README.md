# ArduinoJson_LittleFS_parse_json
Code blocks that use ArduinoJson and LittleFS to parse JSON objects saved as a .txt file

A tools folder with the correct file structure and names is uploaded in this repo as well, you can download the folder and put it into the Arduino folder to use it immediately, it has the very latest tool for esp32 and esp8266 at the time of writing.

To get the latest version of the tools, follow instructions on how to download the tools and replace the .jar file in the respective tool folder 
from here:  
- For ESP8266: https://github.com/earlephilhower/arduino-esp8266littlefs-plugin
- For ESP32:   https://github.com/lorol/arduino-esp32littlefs-plugin

Download the .zip file and open the .ino file
The data folder has to be in the same directory of the .ino file

- you may want to change delay(1); to delayMicroseconds(10); if you dont want to wait so long
