#include <dht11_th.h>

const int DHTPin = 2;
DHT11 dht(DHTPin);
int presence, rh_byte1, rh_byte2, temp_byte1, temp_byte2, SUM, TEMP;
float t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello");

  dht.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  presence = dht.checkRespone();
  rh_byte1 = dht.read();
  rh_byte2 = dht.read();
  temp_byte1 = dht.read();
  temp_byte2 = dht.read();
  SUM = dht.read();
  TEMP = temp_byte1;
  t = (float)TEMP;
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("*C\n");
}
