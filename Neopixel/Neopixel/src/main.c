/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic usage of on-board LED and button
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>
#include <stdio_serial.h>
#include "conf_test.h"
#include "conf_clocks.h"
#include "sio2host.h"
#include "tc_configuration.h"
#include "neopixel.h"
#include "buzzer.h"
	
	
int main (void)
{
	system_init();
	
	sio2host_init();
	
	//configure_tc();
	
	delay_init();
	
	//Interrup related block of code
	
	//system_interrupt_enable_global();
	//cpu_irq_disable();
	bool inter;
	inter = system_interrupt_is_global_enabled();
	printf(" Interrups state: %s\n", inter?"1":"0");
	
	//Neopixel_showPattern();
	/*
	int delay = 200;
	int j= 0;
	
	int perm[7][3]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1},{1,1,1}};
		
	while (1){
		
		Neopixel_showColor(16*perm[j][0],16*perm[j][1],16*perm[j][2]);
		
		delay_ms(delay);
		
		j++;
		
		if (j>6) j=0;
		
		if (port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE) {
		}
		
	}
	*/	
	
	
	while(1)
	{	
	 if(!songStarts)
	 { // Start song
		 //digitalWrite(blueLED,HIGH); // Light the onboard Blue LEDwhile the song plays
		 songStarts = true;
		 //begin_rtttl(songs[random(sizeof(songs)/sizeof(char *))]);
		 begin_rtttl(song);
	 }
	 
	 if (!next_rtttl())
	 { // Play next note
		 //digitalWrite(blueLED,LOW); // Turn off the onboard Blue LED.
		 songStarts = false;
		 if(DEBUG) printf("Done!");
		 delay_ms(200);
		 break;
	 }
	}
	
	
	

	
	
}
