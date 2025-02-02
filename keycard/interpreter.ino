#include <string>

#include "interpreter.h"
#include "common.h"

const char COMMAND_DELIMITER = ',';
const char COMMAND_INSIDE_DELIMITER = ' ';

#define FORWARDS_TOKEN "FORWARDS"
#define BACKWARDS_TOKEN "BACKWARDS"
#define LEFT_TOKEN "LEFT"
#define RIGHT_TOKEN "RIGHT"

CommandInterpreter::CommandInterpreter() {}

CommandInterpreter::Token CommandInterpreter::commandToToken(String command, int& value) {
  int endPos = 0;
  if ((endPos = command.indexOf(COMMAND_INSIDE_DELIMITER)) == -1) {
    // Single word command
    endPos = command.length();
  }
  String commandToken = command.substring(0, endPos);

  String end = command.substring(endPos, command.length());

  if (end.length() != 0) {
    value = std::stoi(end.c_str());
  }

  if (commandToken == FORWARDS_TOKEN) {
    return Token::FORWARDS;
  } else if (commandToken == BACKWARDS_TOKEN) {
    return Token::BACKWARDS;
  } else if (commandToken == LEFT_TOKEN) {
    return Token::LEFT;
  } else if (commandToken == RIGHT_TOKEN) {
    return Token::RIGHT;
  } else {
    return Token::ERROR;
  }
}

void CommandInterpreter::send(String message) {
  String command;
  size_t endPos = 0;
  while (true) {
#ifdef DEBUG
    Serial.println("loop");
    Serial.println(message);
#endif
    if ((endPos = message.indexOf(COMMAND_DELIMITER)) == -1) {
#ifdef DEBUG
      Serial.println("----- END POS NOT FOUND -----");
#endif
      // Either no commands or last command
      endPos = message.length();
    }

    if (endPos == 0) return;

    command = message.substring(0, endPos);

#ifdef DEBUG
    Serial.println("-- endpos --");
    Serial.println(endPos);
    Serial.println("Interpreting");
    Serial.println(command);
#endif

    int value = 0;

    Token commandToken = commandToToken(command, value);

    switch (commandToken) {
      case Token::FORWARDS:
#ifdef DEBUG
        Serial.println("Forwards");
#endif
        robot.forwards(value);
        break;
      case Token::BACKWARDS:
#ifdef DEBUG
        Serial.println("Backwards");
#endif
        robot.backwards(value);
        break;
      case Token::LEFT:
#ifdef DEBUG
        Serial.println("Left");
#endif
        robot.left(value);
        break;
      case Token::RIGHT:
#ifdef DEBUG
        Serial.println("Right");
#endif
        robot.right(value);
        break;
      default:
#ifdef DEBUG
        Serial.println("ERROR OCCURED");
#endif
        break;
    }

    message.remove(0, endPos + 1);
    delay(500);
  }
}