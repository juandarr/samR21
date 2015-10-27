/*
 * basic_colors.h
 *
 * Created: 10/26/2015 4:09:44 PM
 *  Author: Juan Rios
 */ 


#ifndef BASIC_COLORS_H_
#define BASIC_COLORS_H_

void green()
{
	//GREEN
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
}

void red()
{
	//GREEN
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	
	
	
}

void blue()
{
	//GREEN
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
}

void cyan(void)
{
	//GREEN
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	//RED
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
}


void yellow()
{
	//GREEN
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	
	//RED
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");

	//BLUE
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
}

//Magenta
void magenta(void)
{

	
	//GREEN
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");

	//RED
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;");
	
	//BLUE
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	port_pin_set_output_level(neo_PIN, true);
	asm( "nop;");
	port_pin_set_output_level(neo_PIN, false);
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
	asm( "nop;nop;nop;nop;nop;nop;nop;nop;nop;nop;");
	
}



#endif /* BASIC_COLORS_H_ */