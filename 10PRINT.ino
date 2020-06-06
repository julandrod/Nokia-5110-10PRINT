/*
Este programa crea una 
*/

// Librerias necesarias 
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include <SPI.h>

// Pines del LCD Nokia 5110
#define RST 12
#define CE  13
#define DC  11
#define DIN  10
#define CLK  9

Adafruit_PCD8544 display = Adafruit_PCD8544(CLK, DIN, DC, CE, RST);

void setup(){
	// setup display
	display.begin();
	display.setContrast(40);
	display.clearDisplay();
	display.display();

	// Defino tamaño del texto y color
	display.setTextSize(1);
	display.setTextColor(BLACK);
	display.clearDisplay();	

	// Esta funcion evita que la secuencia random sea siempre la misma
	randomSeed(analogRead(0));

}

float randNumber;
int width = 83; 	// Ancho del lcd-1
int height = 47;	// Altura del lcd-1
int x = 0, y = 0, offset = 4;

void loop(){	
	while(y <= height){
		// Genero un numero aleatorio entre 0.00 y 1
		randNumber = random(101) / 100.0 ;

		// Establezco la probabilidad de aparicion de cada linea
		if(randNumber < 0.5)
			display.drawLine(x, y, x+offset, y+offset, 1);		
		else 
			display.drawLine(x, y+offset, x+offset, y, 1);
		
		x += offset;

		if(x >= width){
			x = 0;
			y += offset;
		}

		delay(10);
		display.display();
	}
}