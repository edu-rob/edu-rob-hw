#include "ICHack.h"

#include "interpreter.h"
#include "common.h"

#define DEBUG

CommandInterpreter interpreter;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  delay(1000);
#endif
}


void loop() {
  String commands;
  if ((commands = Serial.readString()) == "") {
    return;
  }
  
  commands.trim();
  debugPrint("Sending ");
  debugPrint(commands);
  interpreter.send(commands);
}