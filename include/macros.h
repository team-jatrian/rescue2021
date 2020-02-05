#ifndef MACROS_H
#define MACROS_H

#define spn(x) Serial.println(x)
#define sp(x) Serial.print(x)
#define ar(x) analogRead(x)
#define aw(x, y) analogWrite(x, y)
#define dr(x) digitalReadFast(x)
#define dw(x, y) digitalWriteFast(x, y)
#define repeatMillis(x) for(uint32_t tx = millis(); millis() < tx + x;)

#endif