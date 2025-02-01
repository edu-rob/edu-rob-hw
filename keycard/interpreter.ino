#include "interpreter.h"
#include "common.h"

const char COMMAND_DELIMITER = '\n';
const char COMMAND_INSIDE_DELIMITER = ' ';

#define FORWARDS_TOKEN "FORWARDS"
#define BACKWARDS_TOKEN "BACKWARDS"
#define LEFT_TOKEN "LEFT"
#define RIGHT_TOKEN "RIGHT"

CommandInterpreter::CommandInterpreter() {}

CommandInterpreter::Token CommandInterpreter::commandToToken(String command) {
  int endPos;
  if ((endPos = command.indexOf(COMMAND_INSIDE_DELIMITER)) == -1) {
    // Single word command
    endPos = command.length();
  }
  String commandToken = command.substring(0, endPos);

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
  size_t startPos = 0;
  size_t endPos = 0;
  while (true) {
    if ((endPos = message.indexOf(COMMAND_DELIMITER)) == -1) {
      // Either no commands or last command
      endPos = message.length();
      if (startPos == message.length()) {
        return;
      }
    }

    command = message.substring(startPos, endPos);

    debugPrint("-- startpos --");
    debugPrint(startPos);
    debugPrint("-- endpos --");
    debugPrint(endPos);
    debugPrint("Interpreting");
    debugPrint(command);

    startPos = endPos;
    Token commandToken = commandToToken(command);

    switch (commandToken) {
      case Token::FORWARDS:
        debugPrint("Forwards");
        robot.forwards();
        break;
      case Token::BACKWARDS:
        debugPrint("Backwards");
        robot.backwards();
        break;
      case Token::LEFT:
        debugPrint("Left");
        robot.left();
        break;
      case Token::RIGHT:
        debugPrint("Right");
        robot.right();
        break;
      default:
        debugPrint("ERROR OCCURED");
        break;
    }
  }
}