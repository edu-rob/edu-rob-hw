#include <string>

#include "interpreter.h"

const char COMMAND_DELIMITER = '\n';

CommandInterpreter::CommandInterpreter() {}

CommandInterpreter::Token CommandInterpreter::commandToToken(std::string command) {
  return Token::FORWARDS;
}

void CommandInterpreter::send(std::string message) {
  std::string command;
  size_t startPos = 0;
  size_t endPos = 0;
  while ((command = message.substr(startPos, endPos = message.find(COMMAND_DELIMITER))) != "") {
    Token commandToken = commandToToken(command);
    switch (commandToken) {
      case Token::FORWARDS:
        Serial.println("Forwards");
      case Token::BACKWARDS:
        Serial.println("Backwards");
      case Token::LEFT:
        Serial.println("Left");
      case Token::RIGHT:
        Serial.println("Right");
    }
  }
}