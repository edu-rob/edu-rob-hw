#ifndef COMMON_H
#define COMMON_H

#ifdef DEBUG
#define debugPrint(msg) Serial.println(msg)
#elif
#define debugPrint(msg)
#endif

#endif