//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"
#include "BTAddress.h"

#include <esp_system.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  delay(400);
  String device_name = "ESP32test" ;
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  Serial.println(device_name);
  uint8_t buff[6] ; 
  SerialBT.getBtAddress(buff) ;
  Serial.printf("Mac address is : 0x%x%x%x%x%x%x\n", buff[5], buff[4], buff[3], buff[2], buff[1], buff[0]) ; 
}



void loop() {

// if (SerialBT.available()) {
//   Serial1.write(SerialBT.read());
// }
  // BTAddress(mac) ; 
  //esp_efuse_get_mac(mac); 
  // printf("UUID is :  0x%0x%0x%0x%0x%", mac[0], max[1], max[2], max[3], max[4]);
  Serial.println("FORWARDS") ;
  delay(1000) ;
}