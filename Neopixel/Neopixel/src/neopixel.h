/*
 * neopixel.h
 *
 * Created: 10/24/2015 9:58:37 PM
 *  Author: Juan Rios
 */ 


#ifndef NEOPIXEL_H_
#define NEOPIXEL_H_

#include "basic_colors.h"
uint16_t numBytes = 3;

void Neopixel_showColor(uint8_t red, uint8_t green, uint8_t blue)
{
   
	//system_interrupt_enter_critical_section(); // Need 100% focus on instruction timing

	volatile uint32_t
	c,    // 24-bit pixel color
	mask; // 8-bit mask
	volatile uint16_t i = numBytes; // Output loop counter
	volatile uint8_t
	j,              // 8-bit inner loop counter
	g,              // Current green byte value
	r,              // Current red byte value
	b;              // Current blue byte value

	
		while(i) { // While bytes left... (3 bytes = 1 pixel)
			mask = 0x800000; // reset the mask
			i = i-3;      // decrement bytes remaining
			g = green;   // Next green byte value
			r = red;   // Next red byte value
			b = blue;   // Next blue byte value
			c = ((uint32_t)g << 16) | ((uint32_t)r <<  8) | b; // Pack the next 3 bytes to keep timing tight
			printf("Hexa: %04x\nBin: ", c);
			j = 0;        // reset the 24-bit counter
			do {
				
				if (c & mask) { // if masked bit is high
					
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
				
			} while ( ++j < 24 ); // ... pixel done
		} // end while(i) ... no more pixels
	
	//system_interrupt_leave_critical_section();
}


//This function shows a pattern of colors 
void Neopixel_showPattern()
{
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
		
		delay_ms(200);
		j++;
		if (j>5)
		{
			j=0;
		}
	}
	
}


#endif /* NEOPIXEL_H_ */