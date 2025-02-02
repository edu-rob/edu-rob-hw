#include "ICHack.h"

#include "interpreter.h"
#include "common.h"

#define DEBUG 1

CommandInterpreter interpreter;

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  delay(500);
  Serial.println("Starting...");
#endif
  Serial1.setFIFOSize(512);
  Serial1.begin(9600);
  delay(500);
}

void loop() {
  static int i = 0;
  i++;
  String commands = "";
#ifdef DEBUG
  if ((commands = Serial.readString()) == "") {
    Serial.printf("Not Received Serial %d\n", i);
  }
#endif

  if (commands == "" && (commands = Serial1.readStringUntil('\n')) == "") {
#ifdef DEBUG
    Serial.printf("Not Received UART %d\n", i);
#endif
    return;
  }

#ifdef DEBUG
  Serial.println("------ Received ------");
#endif

  commands.trim();

#ifdef DEBUG
  Serial.println("Sending ");
  Serial.println(commands);
#endif

  interpreter.send(commands);
}