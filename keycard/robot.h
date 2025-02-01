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
};

#endif