/*
 * tc_configuration.h
 *
 * Created: 10/26/2015 3:47:06 PM
 *  Author: Juan Rios
 */ 


#ifndef TC_CONFIGURATION_H_
#define TC_CONFIGURATION_H_

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



#endif /* TC_CONFIGURATION_H_ */