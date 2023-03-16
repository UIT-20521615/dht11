#ifndef dht11_th
#define dht11_th

#include "Arduino.h"

class DHT {
    public:
    DHT(uint8_t pin);
    void DHT11_Start(void);
    uint8_t Check_Response(void);
    uint8_t DHT11_Read(void);

    private:
    uint8_t _pin;
};


#endif