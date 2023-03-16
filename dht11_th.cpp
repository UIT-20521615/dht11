1#include "dht11_th.h"

DHT::DHT(uint8_t pin) {
    _pin = pin;
}

void DHT::DHT11_Start(void)
{
	pinMode (_pin, OUTPUT);  
	digitalWrite (_pin, 0);  
	delay (18); 
	pinMode(_pin, INPUT_PULLUP);
}

uint8_t DHT::Check_Response(void)
{
	uint8_t Response = 0;
	delayMicroseconds(40);
	if (!(digitalRead (_pin)))
	{
		delayMicroseconds (80);
		if (digitalRead (_pin)) Response = 1;
		else Response = -1;
	}
	while (digitalRead (_pin));   

	return Response;
}

uint8_t DHT::DHT11_Read(void)
{
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(digitalRead (_pin)));  
		delayMicroseconds (40);   
		if (!(digitalRead (_pin))) 
		{
			i&= ~(1<<(7-j));   
		}
		else i|= (1<<(7-j)); 
		while ((digitalRead (_pin)));
	}
	return i;
}