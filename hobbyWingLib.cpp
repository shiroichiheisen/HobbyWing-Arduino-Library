#include "hobbyWingLib.hpp"

hobbyWingLib::hobbyWingLib(uint8_t pwmChannel, uint8_t pwmPin, uint8_t pwmResolution)
{
    this->pwmChannel = pwmChannel;
    this->pwmPin = pwmPin;
    this->pwmResolution = pwmResolution;
}

void hobbyWingLib::begin()
{
    ledcSetup(pwmChannel, 50, pwmResolution);
    ledcAttachPin(pwmPin, pwmChannel);
}

void hobbyWingLib::setPWMus(uint16_t PWMus)
{
    uint8_t maxDuty = (1 << pwmResolution) - 1;
    uint16_t periodMicroseconds = 1000000 / 50;
    uint16_t duty = map(PWMus, 0, periodMicroseconds, 0, maxDuty);
    setPWM(duty);
}

void hobbyWingLib::setPWMPercentage(uint8_t percentage)
{
    if (percentage > 100)
        percentage = 100;

    uint16_t dutyCycle = map(percentage, 0, 100, 0, (1 << pwmResolution) - 1);
    setPWM(dutyCycle);
}

void hobbyWingLib::setPWM(uint16_t PWMduty)
{
    ledcWrite(pwmChannel, PWMduty);
}