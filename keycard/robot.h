#ifndef ROBOT_H
#define ROBOT_H

class Robot {
public:
  Robot();
  void forwards(int meters = 1);
  void backwards(int meters = 1);
  void left(int deg = 90);
  void right(int deg = 90);
private:
  enum class Motor { 
    RIGHT,
    LEFT
  };
  void stop();
  void controlMotor(Motor motor, int8_t speed);

  const int moveDelay = 300;
  const int spinDelay = 300;
};

#endif