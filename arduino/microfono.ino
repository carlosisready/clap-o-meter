#include <LiquidCrystal.h>

#define micro A0

int lectura = 0; // Lectura del microfono
int valorMax = 0; // Valor máximo obtenido del micrófono
int valorMin = 0; // Valor mínimo obtenido del micrófono

LiquidCrystal pantalla(2,3,4,5,6,7);
arduinoFFT fft = arduinoFFT();


void setup()
{
     pantalla.begin(16, 2);
     valorMax = analogRead(micro);
     valorMin = valorMax;
     Serial.begin(9600);
}

void loop()
{
  lectura = analogRead(micro);

  // CALCULAMOS LOS VALORES DE PICO DE LA ENTRADA
    if (lectura > valorMax)
      valorMax = lectura;

    if (lectura < valorMin)
      valorMin= lectura;

    // Dibujamos valores en la pantalla

    pantalla.setCursor(0,0);
    pantalla.print("Entrada: ");
    pantalla.print(lectura);
    pantalla.setCursor(0, 1);
    pantalla.print("M: "); 
    pantalla.print(valorMax);
    pantalla.print(" m: "); 
    pantalla.print(valorMin);
    
    delay(10);
}
