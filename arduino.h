#ifndef ARDUINO_H_INCLUDED
#define ARDUINO_H_INCLUDED

typedef struct{
    char *dev_name;
    char *ard_return;
}ArduinoMaster;

void InitArduino(ArduinoMaster *ard_ms);

void read_from_arduino(ArduinoMaster *ard_ms);

int ArduinoKeyCheck(ArduinoMaster *ard_ms, char *key_str);


#endif // ARDUINO_H_INCLUDED
