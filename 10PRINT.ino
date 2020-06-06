#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include <SPI.h>

// LCD pins
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

	// Setup size and text color
	display.setTextSize(1);
	display.setTextColor(BLACK);
	display.clearDisplay();	

	// This function avoid the same random sequence
	randomSeed(analogRead(0));

}

float randNumber;
int width = 83; 	// Width of the LCD - 1
int height = 47;	// Height of the LCD -1
int x = 0, y = 0, offset = 4; 

void loop(){	
	while(y <= height){
		// Random number between 0.00 and 1
		randNumber = random(101) / 100.0 ;

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
