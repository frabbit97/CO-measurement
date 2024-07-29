#include "Arduino.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

float voltage;
uint16_t level;
#define coefficient_A 19.32
#define coefficient_B -0.64
void loop() {
  // put your main code here, to run repeatedly:
  
  //return adc level 0-4095;
  level=analogRead(ADC); 

  /*return the voltage in mV
  * for asr650x, max value can be read is 2400mV
  * for asr6601,value can be read is 100mV-1100mV
  */
  voltage=analogReadmV(ADC);
  //formula presa dalla libreria MQ7
  float v_in=2.35;
  float v_out=voltage/1000;
  float ratio=(v_in-v_out)/v_out;
  float ppm=coefficient_A*pow(ratio,coefficient_B);
  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.printf(",  level: ");
  Serial.print(level);
  Serial.printf(",  ppm: ");
  Serial.println(ppm);
  delay(1000);
}
//0-9	Nessun effetto avverso noto per esposizione a lungo termine
//10-34	Limite di esposizione medio ponderato su 8 ore (EPA, OSHA, NIOSH)
//35	Limite di esposizione medio ponderato su 1 ora (EPA, WHO)
//50	Limite di esposizione medio ponderato su 8 ore (OSHA)
//70	Possibili sintomi lievi dopo esposizione prolungata
//150-200	Mal di testa, nausea, disorientamento, pericolo di incoscienza
//>400	Grave pericolo per la salute, possibile morte con esposizione prolungata