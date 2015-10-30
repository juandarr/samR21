/*
 * neopixel.h
 *
 * Created: 10/24/2015 9:58:37 PM
 *  Author: Juan Rios
 */ 


#ifndef NEOPIXEL_H_
#define NEOPIXEL_H_

//Library with basic colors defined as a constant stream of bits (no loops involved)
#include "basic_colors.h"




/*** Define struct to store the fundamental data to work with a neopixel ***/
struct neopixel
{
	uint8_t pin; //MCU pin assigned for the neopixel
	uint8_t red; //8 bit number to turn on red led (0-255)
	uint8_t green; //8 bit number to turn on green led (0-255)
	uint8_t blue; // 8 bit number to turn on blue led (0-255)
	uint16_t numLeds; // Number of leds of the neopixel strip
	uint8_t brightness; // Brightness as percentage (0-100)
	
};

typedef struct neopixel Neopixel ;

void neopixelDefaults(Neopixel *neopixel_config);
void neopixelBegin(Neopixel *neopixel_config);
//void neopixelShow(Neopixel *neopixel_config);
void neopixelShow(uint8_t red, uint8_t green, uint8_t blue);
void neopixel_setColor(Neopixel *neopixel_config, uint8_t r, uint8_t g, uint8_t b );
void neopixel_setBrightness(Neopixel *neopixel_config, uint8_t brightness );
void neopixel_clear(Neopixel *neopixel_config);


/*** Assign the default values for each parameter of the neopixel ***/
void neopixelDefaults(Neopixel *neopixel_config)
{
	neopixel_config->pin = neo_PIN; 
	neopixel_config->brightness = 0;
	neopixel_config->numLeds = 1;
	neopixel_config->red = 0;
	neopixel_config->green = 0;
	neopixel_config->blue = 0;
}


void neopixelBegin(Neopixel *neopixel_config)
{
	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);

	/* Configure Neopixel control output */
	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(neopixel_config->pin, &pin_conf);
	port_pin_set_output_level(neopixel_config->pin, false);	
}


//void neopixelShow(Neopixel *neopixel_config)
void neopixelShow(uint8_t red, uint8_t green, uint8_t blue)
{
	volatile uint32_t
	c,    // 24-bit pixel color
	mask; // 8-bit mask
	
	volatile uint8_t
	j,              // 8-bit inner loop counter
	g,              // Current green byte value
	r,              // Current red byte value
	b,              // Current blue byte value
	i = 3; //neopixel_config->numLeds*3; // Number of bytes
	
		while(i) { // While bytes left... (3 bytes = 1 pixel)
			mask = 0x800000; // reset the mask
			i = i-3;      // decrement bytes remaining
			g = green;//neopixel_config->green;   // Next green byte value
			r = red;//neopixel_config->red;   // Next red byte value
			b = blue;//neopixel_config->blue;   // Next blue byte value
			c = ((uint32_t)g << 16) | ((uint32_t)r <<  8) | b; // Pack the next 3 bytes to keep timing tight
			printf("Hexa: %04x\nBin: ", c);
			j = 0;        // reset the 24-bit counter
			do {
				
				if (c & mask) { // if masked bit is high
					//neopixel_config->pin
					port_pin_set_output_level(neo_PIN, true);
					// WS2812 spec             700ns HIGH
					// Adafruit on Arduino    (meas. 812ns)
					// This lib on Spark Core (meas. 804ns)
					// This lib on Photon     (meas. 792ns)
					
					//16 MHz
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
					
					/*48MHz
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;"
					);*/
					
					// WS2812 spec             600ns LOW
					// Adafruit on Arduino    (meas. 436ns)
					// This lib on Spark Core (meas. 446ns)
					// This lib on Photon     (meas. 434ns)
					//neopixel_config->pin
					port_pin_set_output_level(neo_PIN, false); //LOW
					
					//16 MHz
					asm( "nop;nop;nop;nop;");
					
					/* 48MHz
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					); */
					//printf("1");
				}
				else { // else masked bit is low
					// WS2812 spec             350ns HIGH
					// Adafruit on Arduino    (meas. 312ns)
					// This lib on Spark Core (meas. 318ns)
					// This lib on Photon     (meas. 308ns)
					//neopixel_config->pin
					port_pin_set_output_level(neo_PIN, true);
					//16 MHz
					asm( "nop;");
					
					/* 48MHz
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					     "nop;nop;nop;"
					);
					*/
					// WS2812 spec             800ns LOW
					// Adafruit on Arduino    (meas. 938ns)
					// This lib on Spark Core (meas. 944ns)
					// This lib on Photon     (meas. 936ns)
					port_pin_set_output_level(neo_PIN, false); // LOW
					
					// 16 MHz
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
					
					/* 48 MHz
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					"nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					"nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					"nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					);
					*/
					//printf("0");
				}
				mask >>= 1;
				
				//Delay between each bit - looks like it is not need because of the if and loop consuming clock cycles
				//asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
			} while ( ++j < 24 ); // ... pixel done when 24 bits have been sent
		} 
}


void neopixel_setColor(Neopixel *neopixel_config, uint8_t r, uint8_t g, uint8_t b )
{
	neopixel_config->red = r;
	neopixel_config->green = g;
	neopixel_config->blue = b;
	//neopixelShow(neopixel_config);
}

void neopixel_setBrightness(Neopixel *neopixel_config, uint8_t brightness )
{
	neopixel_config->brightness = brightness;
	//neopixelShow(neopixel_config);
}

void neopixel_clear(Neopixel *neopixel_config)
{
	neopixel_config->red = 0;
	neopixel_config->green = 0;
	neopixel_config->blue = 0;
	//neopixelShow(neopixel_config);
}

//This function shows a pattern of colors 
void Neopixel_showPattern(int delay)
{
	if (delay==NULL) delay=200;
	void (*p[6][6])() ={{red, cyan, green, blue,yellow,magenta},{cyan, green, blue,yellow,magenta,red},
	{green, blue,yellow,magenta,red, cyan},{blue,yellow,magenta,red, cyan, green},
	{yellow,magenta,red, cyan, green, blue},{magenta,red, cyan, green, blue,yellow}}; //Array containing different frames for the animation pattern
		
	int j = 0; //Used to access each animation in the while loop
	
	
	while (1)
	{
		for(int i = 0; i < 3;i++)
		{
			(*p[j][0]) ();
			(*p[j][1]) ();
			(*p[j][2]) ();
			(*p[j][3]) ();
			(*p[j][4]) ();
			(*p[j][5]) ();
		}
		
		delay_ms(delay);
		j++;
		if (j>5)
		{
			j=0;
		}
	}
	
}


#endif /* NEOPIXEL_H_ */