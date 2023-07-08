/*
   IMPORTANT NOTE!!!!!
   follow the instructions on setting up littleFS on esp8266 here FIRST:
   https://github.com/earlephilhower/arduino-esp8266littlefs-plugin

   Make sure you close your serial monitor before uploading files
*/

#include "LittleFS.h"
#include <ArduinoJson.h>
#define FILE_SIZE 1024 //define file size
StaticJsonDocument<FILE_SIZE> doc;
char json[FILE_SIZE];

void setup() {
  Serial.begin(115200);
  Serial.println();

  /*=========================================================*/

  //check that data folder is mounted successfully
  if (!LittleFS.begin()) {
    Serial.println("Error mounting data folder");
    return;
  }

  /*=========================================================*/

  /*
     open the file, "r" is read, to delete all files,
     clear the data folder and then reupload using littlefs
     data upload. In my tests, you can save
     a JSON object in a text file.
     ex: {"data":"hello world"}
  */
  File file = LittleFS.open("/json_text.txt", "r");
  if (!file) {
    Serial.println("file read error");
    return;
  }

  /*=========================================================*/

  /*
     read every character from the file until EOF, put
     it into the json char buf and close the file
  */
  uint8_t i = 0;
  while (file.available()) {
    char input_char = file.read();
    Serial.write(input_char);
    json[i] = input_char;
    i++;
    delay(1);
  }
  file.close();
  Serial.println();

  /*=========================================================*/

  //deserialise json
  DeserializationError error = deserializeJson(doc, json);
  // Test if parsing succeeds.
  if (error) {
    Serial.println(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  //parse json
  String json_test = doc["data"].as<String>();
  double json_double = doc["double"].as<double>();
  Serial.println(json_test);
  Serial.println(json_double);
  /*=========================================================*/


}

void loop() {

}
