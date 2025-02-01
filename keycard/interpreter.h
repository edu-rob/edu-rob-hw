#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

#include "robot.h"

class CommandInterpreter {
public:
  CommandInterpreter();
  void send(std::string message);
private:
  enum class Token {
    FORWARDS,
    BACKWARDS,
    LEFT,
    RIGHT
  };

  Token commandToToken(std::string command);
  Robot robot;
};

#endif