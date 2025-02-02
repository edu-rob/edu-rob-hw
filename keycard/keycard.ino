#include "ICHack.h"

#include "interpreter.h"
#include "common.h"

#define DEBUG 1

CommandInterpreter interpreter;


// Create the frame buffer. The first 24 bits of each uint32_t
// represent one column of the LED matrix. You can write to this
// buffer directly and patters will appear on the display.
volatile uint32_t fb[FRAME_BUFFER_WIDTH];

void setup() {
#ifdef DEBUG
  Serial.begin(115200);
  delay(500);
  Serial.println("Starting...");
#endif
  Serial1.setFIFOSize(512);
  Serial1.begin(9600);
  delay(500);
    // Initialise the display by passing it the frame buffer. This
  // will create a thread that continuously renders the frame
  // buffer to the matrix.
  display_init(fb);
  delay(1000);
  pinMode(LOGO_I, OUTPUT);
  digitalWrite(LOGO_I, HIGH); /* turn the I on */
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
