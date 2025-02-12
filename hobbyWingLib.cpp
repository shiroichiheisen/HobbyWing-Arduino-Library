#include "hobbyWingLib.hpp"

hobbyWingLib::hobbyWingLib(uint8_t pwmChannel, uint8_t pwmPin, uint8_t pwmResolution)
{
    this->pwmChannel = pwmChannel;
    this->pwmPin = pwmPin;
    this->pwmResolution = pwmResolution;

    ledcSetup(this->pwmChannel, 500, this->pwmResolution);
    ledcAttachPin(this->pwmPin, this->pwmChannel);

    minPwmDuty = ((1 << pwmResolution) / 2) - 1;
    maxPwmDuty = (1 << pwmResolution) - 1;
    maxPwmDuty = maxPwmDuty * 0.95;
}

void hobbyWingLib::setPWMus(uint16_t PWMus)
{
    if (PWMus < 1050)
        PWMus = 1050;
    if (PWMus > 1950)
        PWMus = 1950;
    setPWM(map(PWMus, 1050, 1950, minPwmDuty, maxPwmDuty));
}

void hobbyWingLib::setPWMPercentage(uint8_t percentage)
{
    if (percentage > 100)
        percentage = 100;
    setPWM(map(percentage, 0, 100, minPwmDuty, maxPwmDuty));
}

void hobbyWingLib::setPWM(uint16_t PWMduty)
{
    ledcWrite(pwmChannel, PWMduty);
}