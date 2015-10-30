/*
 * neopixel_config.h
 *
 * Created: 10/28/2015 8:41:04 PM
 *  Author: Juan Rios
 */ 


#ifndef NEOPIXEL_CONFIG_H_
#define NEOPIXEL_CONFIG_H_

#include "neopixel.h"

Neopixel neo;

void neopixel_init()
{
neopixelDefaults(&neo);
neopixelBegin(&neo);
}

#endif /* NEOPIXEL_CONFIG_H_ */