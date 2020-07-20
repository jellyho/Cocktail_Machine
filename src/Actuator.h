// Cocktail.h

#if 0
#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


class Actuator
{
private:
    int PIN_A, PIN_B;

public:
    Actuator(int a, int b);
    void up();
    void down();
    void idle();
};


Actuator::Actuator(int a, int b) {
    PIN_A = a;
    PIN_B = b;
    pinMode(PIN_A, OUTPUT);
    pinMode(PIN_B, OUTPUT);
}

void Actuator::up() {
    digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_B, LOW);
}

void Actuator::down() {
    digitalWrite(PIN_A, LOW);
    digitalWrite(PIN_B, HIGH);
}

void Actuator::idle() {
    digitalWrite(PIN_A, LOW);
    digitalWrite(PIN_B, LOW);
};

#endif