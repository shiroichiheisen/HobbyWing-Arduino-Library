#ifndef hobbyWingLib_hpp
#define hobbyWingLib_hpp

#include <Arduino.h>

class hobbyWingLib
{
public:
    hobbyWingLib(uint8_t pwmChannel, uint8_t pwmPin, uint8_t pwmResolution);
    void begin();
    void setPWMus(uint16_t PWMus);
    void setPWMPercentage(uint8_t percentage);

private:
    void setPWM(uint16_t PWMduty);
    uint8_t
        pwmChannel,
        pwmPin,
        pwmResolution;
};

#endif