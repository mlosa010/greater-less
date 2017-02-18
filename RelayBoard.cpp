#include <Arduino.h>
#include "RelayBoard.h"

RelayBoard::RelayBoard() {}

RelayBoard::RelayBoard(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e,uint8_t f)
{
    pinMode(a, OUTPUT);
    pinMode(b, OUTPUT);
    pinMode(c, OUTPUT);
    pinMode(d, OUTPUT);
    pinMode(e, OUTPUT);
    pinMode(f, OUTPUT);
    this->pin[0] = a;
    this->pin[1] = b;
    this->pin[2] = c;
    this->pin[3] = d;
    this->pin[4] = e;
    this->polaritypin = f;

    for (int i = 0; i < PINS; i++) {
        digitalWrite(this->pin[i], HIGH);
    }
    digitalWrite(this->polaritypin, HIGH);
}

RelayBoard::~RelayBoard() {}

void RelayBoard::select(uint8_t p)
{
    if (p < 0 || p >= PINS) return;
    for (int i = 0; i < PINS; i++) {
        digitalWrite(this->pin[i], HIGH);
    }
    digitalWrite(this->pin[p], LOW);
}

void RelayBoard::switchpolarity()
{
  digitalWrite(this->polaritypin, !digitalRead(this->polaritypin));
}

