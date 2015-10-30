/*
 * buzzer.h
 *
 * Created: 10/26/2015 4:02:24 PM
 *  Author: Juan Rios
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

#include "ctype.h"

#define OCTAVE_OFFSET 0

#define DEBUG false


// Notes defined in microseconds (Period/2)
// from note C to B, Octaves 3 through 7

int notes[] =   {0,
	3817,3597,3401,3205,3030,2857,2703,2551,2404,2273,2146,2024,
	1908,1805,1701,1608,1515,1433,1351,1276,1205,1136,1073,1012,
	956,903,852,804,759,716,676,638,602,568,536,506,
	478,451,426,402,379,358,338,319,301,284,268,253,
	239,226,213,201,190,179,169,159,151,142,134,127};

//char * song =(char *)"MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";
//char * song =(char *)"American:d=4,o=5,b=100:8g.,16e,c,e,g,2c6,8e.6,16d6,c6,e,f#,2g,g,e.6,8d6,c6,2b,8a.,16b,c6,c6,g,e,c";
//char * song = (char *)"JingleBell:d=8,o=5,b=112:32p,a,a,4a,a,a,4a,a,c6,f.,16g,2a,a#,a#,a#.,16a#,a#,a,a.,16a,a,g,g,a,4g,4c6";
//char * song = (char *)"Beatles_Let_It_Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";
char * song = (char *)"bitter_sweet:d=4,o=5,b=100:8p,32d.6,16p,32f6,16p,32d6,16p,32d#.6,16p,32c6,16p,d#6,32p,32g#6,16p,32d#6,16p,g#6,32p,32g6,16p,32d#.6,16p,g6,8p,32d.6,16p,32f6,16p,32d6,16p,32d#.6,16p,32c6,16p,d#6,32p,32g#6,16p,32d#6,16p,g#6,32p,32g6,16p,32d#.6,16p,g6";


//Tone function receiving output pin, frequency in Hz and duration of tone in mS
void tone(uint32_t pin, uint32_t frequency, uint32_t duration)
{
	int ret = (1/(2*1.756*((float) frequency)))*1000000;
	
	int n = duration/(2*ret/1000.0);
	n = n - (int) (0.44*n);
	if(DEBUG) printf("Playing frequency: %d Hz with delay %u uS, %d veces\n", frequency, 2*(unsigned) ret, n );
	
	
	for(int i = 0; i < n ; i++)
	{
		port_pin_set_output_level(buzzer_PIN, true);
		delay_us(ret);
		port_pin_set_output_level(buzzer_PIN, false);
		delay_us(ret);	
	}
	
}


uint8_t default_dur = 4;
uint8_t default_oct = 6;
uint8_t lowest_oct = 3;
int bpm = 63;
int num;
long wholenote;
long duration;
uint8_t note;
uint8_t scale;
//byte?
bool songStarts = false;
char *songPtr;

void begin_rtttl(char *p)
{
	// Absolutely no error checking in here

	// format: d=N,o=N,b=NNN:
	// find the start (skip name, etc)

	while(*p != ':') p++;    // ignore name
	p++;                     // skip ':'

	// get default duration
	if(*p == 'd')
	{
		p++; p++;              // skip "d="
		num = 0;
		while(isdigit(*p))
		{
			num = (num * 10) + (*p++ - '0');
		}
		if(num > 0) default_dur = num;
		p++;                   // skip comma
	}

	if(DEBUG) { printf("Default duration: %d\n", default_dur); }
		

	// get default octave
	if(*p == 'o')
	{
		p++; p++;              // skip "o="
		num = *p++ - '0';
		if(num >= 3 && num <=7) default_oct = num;
		p++;                   // skip comma
	}

	if(DEBUG) { printf("Default oct: %d\n", default_oct); }

	// get BPM
	if(*p == 'b')
	{
		p++; p++;              // skip "b="
		num = 0;
		while(isdigit(*p))
		{
			num = (num * 10) + (*p++ - '0');
		}
		bpm = num;
		p++;                   // skip colon
	}

	if(DEBUG) { printf("bpm: %d\n", bpm); }

	// BPM usually expresses the number of quarter notes per minute
	wholenote = (60 * 1000L / bpm) * 2;  // this is the time for whole note (in milliseconds)

	if(DEBUG) { printf("Wholenote: %ld\n", wholenote); }
	
	// Save current song pointer...
	songPtr = p;
}

bool next_rtttl() {

	char *p = songPtr;
	// if notes remain, play next note
	if(*p)
	{
		// first, get note duration, if available
		num = 0;
		while(isdigit(*p))
		{
			num = (num * 10) + (*p++ - '0');
		}
		
		if(num) duration = wholenote / num;
		else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

		// now get the note
		note = 0;

		switch(*p)
		{
			case 'c':
			note = 1;
			break;
			case 'd':
			note = 3;
			break;
			case 'e':
			note = 5;
			break;
			case 'f':
			note = 6;
			break;
			case 'g':
			note = 8;
			break;
			case 'a':
			note = 10;
			break;
			case 'b':
			note = 12;
			break;
			case 'p':
			default:
			note = 0;
		}
		p++;

		// now, get optional '#' sharp
		if(*p == '#')
		{
			note++;
			p++;
		}

		// now, get optional '.' dotted note
		if(*p == '.')
		{
			duration += duration/2;
			p++;
		}
		
		// now, get scale
		if(isdigit(*p))
		{
			scale = *p - '0';
			p++;
		}
		else
		{
			scale = default_oct;
		}

		scale += OCTAVE_OFFSET;

		if(*p == ',')
		p++;       // skip comma for next note (or we may be at the end)

		// Save current song pointer...
		songPtr = p;

		// now play the note
		if(note)
		{
			/*
			if(DEBUG) {
				Serial1.print("Playing: ");
				Serial1.print(scale, 10); Serial1.print(' ');
				Serial1.print(note, 10); Serial1.print(" (");
				Serial1.print(notes[(scale - lowest_oct) * 12 + note], 10);
				Serial1.print(") ");
				Serial1.println(duration, 10);
			}
			*/
			float frequency = (1000000.0)/(2.0*notes[(scale - lowest_oct) * 12 + note]);
			
			if(DEBUG) printf("Freq: %u, duration: %u\n", (uint32_t) frequency, (uint32_t) duration);
			
			//Serial.printf("Frequency: %f\n", frequency);
			tone(buzzer_PIN, (uint32_t) frequency, (uint32_t) duration);

			// to distinguish the notes, set a minimum time between them.
			// the note's duration + 30% seems to work well:
			int pauseBetweenNotes = duration * 0.5;//1.30;
			delay_ms(pauseBetweenNotes);
			// stop the tone playing:
			//noTone(tonePin);
		}
		else
		{
			/*
			if(DEBUG) {
				Serial1.print("Pausing: ");
				Serial1.println(duration, 10);
			}
			*/
			delay_ms(duration);
		}
		
		return 1; // note played successfully.
	}
	else {
		return 0; // all done
	}
}

#endif /* BUZZER_H_ */