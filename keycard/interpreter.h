#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "robot.h"

class CommandInterpreter {
public:
  CommandInterpreter();
  void send(String message);
private:
  enum class Token {
    FORWARDS,
    BACKWARDS,
    LEFT,
    RIGHT,
    ERROR
  };

  Token commandToToken(String command);
  Robot robot;
};

#endif