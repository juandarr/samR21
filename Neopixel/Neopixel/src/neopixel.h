/*
 * neopixel.h
 *
 * Created: 10/24/2015 9:58:37 PM
 *  Author: Juan Rios
 */ 


#ifndef NEOPIXEL_H_
#define NEOPIXEL_H_

uint16_t numBytes = 3;

void Neopixel_showColor(uint8_t red, uint8_t green, uint8_t blue)
{
	// Data latch = 1.8 microseconds pause in the output stream.  Rather than
  // put a delay at the end of the function, the ending time is noted and
  // the function will simply hold off (if needed) on issuing the
  // subsequent round of data until the latch time has elapsed.  This
  // allows the mainline code to start generating the next frame of data
  // rather than stalling for the latch.
	//asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//system_interrupt_enter_critical_section(); // Need 100% focus on instruction timing

	volatile uint32_t
	c,    // 24-bit pixel color
	mask; // 8-bit mask
	volatile uint16_t i = numBytes; // Output loop counter
	volatile uint8_t
	j,              // 8-bit inner loop counter
	//*ptr = pixels,   // Pointer to next byte
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
				port_pin_set_output_level(PIN_PA13, true);
				if (c & mask) { // if masked bit is high
					// WS2812 spec             700ns HIGH
					// Adafruit on Arduino    (meas. 812ns)
					// This lib on Spark Core (meas. 804ns)
					// This lib on Photon     (meas. 792ns)
					//asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;"
					);
					// WS2812 spec             600ns LOW
					// Adafruit on Arduino    (meas. 436ns)
					// This lib on Spark Core (meas. 446ns)
					// This lib on Photon     (meas. 434ns)
					port_pin_set_output_level(PIN_PA13, false); //LOW
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
						 "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					);
					//printf("1");
				}
				else { // else masked bit is low
					// WS2812 spec             350ns HIGH
					// Adafruit on Arduino    (meas. 312ns)
					// This lib on Spark Core (meas. 318ns)
					// This lib on Photon     (meas. 308ns)
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					     "nop;nop;nop;"
					);
					// WS2812 spec             800ns LOW
					// Adafruit on Arduino    (meas. 938ns)
					// This lib on Spark Core (meas. 944ns)
					// This lib on Photon     (meas. 936ns)
					port_pin_set_output_level(PIN_PA13, false); // LOW
					asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					"nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					"nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					"nop;nop;nop;nop;nop;nop;nop;nop;nop;"
					);
					//printf("0");
				}
				mask >>= 1;
				
				//Delay between each bit
				//asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
			} while ( ++j < 24 ); // ... pixel done
		} // end while(i) ... no more pixels
	
	//system_interrupt_leave_critical_section();
}

void green()
{
	//GREEN
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
}

void red()
{
	//GREEN
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	
	
	
}

void blue()
{
	//GREEN
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
}

void cyan(void)
{
	//GREEN
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
}


void yellow()
{
	//GREEN
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	
	//RED
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");

	//BLUE
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
}

//Magenta
	void magenta(void)
	{

		
		//GREEN
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");

		//RED
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");
		
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
		
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;");
		
		//BLUE
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		port_pin_set_output_level(PIN_PA13, true);
		asm( "nop;");
		port_pin_set_output_level(PIN_PA13, false);
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
				
		asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
}
#endif /* NEOPIXEL_H_ */