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

/* TCC modules used in tests */
static struct tcc_module tcc_test0_module;

/* Config structs used in tests */

static struct tcc_config tcc_test0_config;

static volatile uint32_t callback_function_entered = 0;

uint32_t period = 60;


static void tcc_callback_function(struct tcc_module *const module_inst)
{
	callback_function_entered += 1;
	//printf("Callback called!");
	port_pin_toggle_output_level(PIN_PA13);
}

void configure_tc()
{
		
		uint32_t duty_cycle = 36;//period/2;
		
		tcc_get_config_defaults(&tcc_test0_config, CONF_TEST_TCC0);
		
		
		tcc_test0_config.counter.period = period;
		tcc_test0_config.counter.clock_source = GCLK_GENERATOR_3;
		//tcc_test0_config.counter.clock_prescaler = TCC_CLOCK_PRESCALER_DIV1024;
		tcc_test0_config.counter.reload_action = TCC_RELOAD_ACTION_PRESC;
		//tcc_test0_config.counter.oneshot = true;
		tcc_test0_config.compare.wave_polarity[TCC_MATCH_CAPTURE_CHANNEL_0] = TCC_WAVE_POLARITY_0;
		tcc_test0_config.compare.wave_generation  = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;//TCC_WAVE_GENERATION_NORMAL_FREQ;////
		tcc_test0_config.compare.match[TCC_MATCH_CAPTURE_CHANNEL_0]  = duty_cycle;

		/* Calculate the theoretical PWM frequency & duty */
		uint32_t frequency_output, duty_output;
		frequency_output = system_clock_source_get_hz(CONF_CLOCK_GCLK_0_CLOCK_SOURCE) / (period+1);
		
		
		
		/* This value is depend on the WaveGeneration Mode */
		duty_output = (uint32_t)(tcc_test0_config.compare.match[TCC_MATCH_CAPTURE_CHANNEL_0] * 100) /
		tcc_test0_config.counter.period;
		
		printf ("Frequency: %u  ---- Duty cycle: %u\n", frequency_output,duty_output);

		tcc_test0_config.pins.enable_wave_out_pin[TCC_MATCH_CAPTURE_CHANNEL_0] = true;
		tcc_test0_config.pins.wave_out_pin[TCC_MATCH_CAPTURE_CHANNEL_0]        = CONF_TEST_PIN_OUT;
		tcc_test0_config.pins.wave_out_pin_mux[TCC_MATCH_CAPTURE_CHANNEL_0]    = CONF_TEST_PIN_MUX;
		tcc_init(&tcc_test0_module, CONF_TEST_TCC0, &tcc_test0_config);

		//tcc_register_callback(&tcc_test0_module, tcc_callback_function, TCC_CALLBACK_CHANNEL_0);
		//tcc_enable_callback(&tcc_test0_module, TCC_CALLBACK_CHANNEL_0);
		
		/* Enable TCC modules */
		tcc_enable(&tcc_test0_module);
}

void toggle_pin_1(){
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;");
}

void toggle_pin_0(){
	port_pin_set_output_level(PIN_PA13, true);
	asm( "nop;");
	port_pin_set_output_level(PIN_PA13, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");

}
	
	
int main (void)
{
	system_init();
	
	sio2host_init();
	
	//configure_tc();
	
	//delay_init();
	
	//system_interrupt_enable_global();
	
	cpu_irq_disable();
	
	bool inter = false;
	
	inter = system_interrupt_is_global_enabled();
	printf(" Interrups state: %s ", inter?"1":"0");
	
	
	
	
	for(int i =0;i<12;i++) {
		
	
		//asm volatile("nop" );
		
		//tcc_restart_counter(&tcc_test0_module);
		/*
		if (port_pin_get_input_level(BUTTON_0_PIN) == BUTTON_0_ACTIVE) {
			
			
			system_interrupt_enter_critical_section();
			*/
		
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
			
			//asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
			
			port_pin_set_output_level(PIN_PA13, true);
			asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
			port_pin_set_output_level(PIN_PA13, false);
			asm( "nop;nop;nop;nop;");
			
			//system_interrupt_leave_critical_section();
			
			/*
		} else {
			
			//port_pin_set_output_level(LED_0_PIN, !LED_0_ACTIVE);
		}
		*/
	}
	
	
}
