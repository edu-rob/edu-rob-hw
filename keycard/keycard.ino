#include "ICHack.h"

#define DEBUG

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  delay(1000);
#endif
}


void loop() {
#ifdef DEBUG
  static int i = 0;
  Serial.printf("Hey from lanyard %d!\n", i);
  i++;
#endif
  delay(1000);
}