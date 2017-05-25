/******************************************************************************
 * MIDIglue 
 
  to use GnusbuinoMIDI-style code on MidiUSB based devices (arduino micro, leonardo, etc...)
 ******************************************************************************/


/*
  GnusbuinoMIDI.h - MIDI over USB library for the Gnusbuino
  http://gnusb.sourceforge.net
  
  Copyright (c) 2012 Michael Egger.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef MIDICLASS_h
#define MIDICLASS_h

#include <inttypes.h>
#include <stdio.h> // for size_t

#include "MIDIUSB.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/
// MIDI Status Bytes

#define MIDI_NOTEOFF			0x80
#define MIDI_NOTEON				0x90
#define MIDI_POLYAFTERTOUCH		0xA0
#define MIDI_CONTROLCHANGE		0xB0
#define MIDI_PROGRAMCHANGE		0xC0
#define MIDI_CHANNELAFTERTOUCH	0xD0
#define MIDI_PITCHBEND			0xE0

//Realtime Messages
#define MIDI_QUARTERFRAME		0xF1
#define MIDI_SONGPOS			0xF2
#define MIDI_SONGSELECT			0xF3
#define MIDI_TIMINGCLOCK		0xF8
#define MIDI_START				0xFA
#define MIDI_CONTINUE			0xFB
#define MIDI_STOP				0xFC

#if defined(__AVR_ATtiny85__)
	#define MIDI_MAX_BUFFER		10
#else
	#define MIDI_MAX_BUFFER		64
#endif

typedef struct {
	unsigned char command;
	unsigned char key;
	unsigned char value;
	unsigned char channel;
} MIDIMessage;

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2


/******************************************************************************
 * MIDI Class
 ******************************************************************************/

class MIDIClass {

public:
	//void write(uint8_t,uint8_t,uint8_t);
	void write(uint8_t,uint8_t,uint8_t,uint8_t = 0);
	uint8_t read(MIDIMessage*);
	size_t print(const char *);
    size_t print(char, int = DEC);
    size_t print(unsigned char, int = DEC);
    size_t print(int, int = DEC);
    size_t print(unsigned int, int = DEC);
    size_t print(long, int = DEC);
    size_t print(unsigned long, int = DEC);
    size_t print(double, int = 2);
	
	size_t println(void);
	size_t println(char, int = DEC);
	size_t println(const char *);
    size_t println(unsigned char, int = DEC);
    size_t println(int, int = DEC);
    size_t println(unsigned int, int = DEC);
    size_t println(long, int = DEC);
    size_t println(unsigned long, int = DEC);
    size_t println(double, int = 2);
	
	
	void sendMIDI(void);
	void flush(void);
	
	void begin(unsigned char = 0);
	
	void receiveMIDI(uint8_t,uint8_t,uint8_t);
	
	private:
		unsigned char _midiOutData[4];

		unsigned char _midiSendEnqueueIdx;
		unsigned char _midiSendDequeueIdx;
		unsigned char _midiSendQueue [MIDI_MAX_BUFFER * 3];
	
		unsigned char _midiRecvEnqueueIdx;
		unsigned char _midiRecvDequeueIdx;
		unsigned char _midiRecvQueue [MIDI_MAX_BUFFER * 3];

		char * _sysex_buffer;
		unsigned char _sysex_idx;
		unsigned char _sysex_len;
		
		unsigned char _analog_midi_thru;

};

	extern MIDIClass MIDI;

#endif

/******************************************************************************
 * MIDI Notes
 ******************************************************************************/

#define _C_1	0
#define _Cis_1	1
#define _D_1	2
#define _Dis_1	3
#define _E_1	4
#define _F_1	5
#define _Fis_1	6
#define _G_1	7
#define _Gis_1	8
#define _A_1	9
#define _Ais_1	10
#define _H_1	11
#define _C0	12
#define _Cis0	13
#define _D0	14
#define _Dis0	15
#define _E0	16
#define _F0	17
#define _Fis0	18
#define _G0	19
#define _Gis0	20
#define _A0	21
#define _Ais0	22
#define _H0	23
#define _C1	24
#define _Cis1	25
#define _D1	26
#define _Dis1	27
#define _E1	28
#define _F1	29
#define _Fis1	30
#define _G1	31
#define _Gis1	32
#define _A1	33
#define _Ais1	34
#define _H1	35
#define _C2	36
#define _Cis2	37
#define _D2	38
#define _Dis2	39
#define _E2	40
#define _F2	41
#define _Fis2	42
#define _G2	43
#define _Gis2	44
#define _A2	45
#define _Ais2	46
#define _H2	47
#define _C3	48
#define _Cis3	49
#define _D3	50
#define _Dis3	51
#define _E3	52
#define _F3	53
#define _Fis3	54
#define _G3	55
#define _Gis3	56
#define _A3	57
#define _Ais3	58
#define _H3	59
#define _C4	60
#define _Cis4	61
#define _D4	62
#define _Dis4	63
#define _E4	64
#define _F4	65
#define _Fis4	66
#define _G4	67
#define _Gis4	68
#define _A4	69
#define _Ais4	70
#define _H4	71
#define _C5	72
#define _Cis5	73
#define _D5	74
#define _Dis5	75
#define _E5	76
#define _F5	77
#define _Fis5	78
#define _G5	79
#define _Gis5	80
#define _A5	81
#define _Ais5	82
#define _H5	83
#define _C6	84
#define _Cis6	85
#define _D6	86
#define _Dis6	87
#define _E6	88
#define _F6	89
#define _Fis6	90
#define _G6	91
#define _Gis6	92
#define _A6	93
#define _Ais6	94
#define _H6	95
#define _C7	96
#define _Cis7	97
#define _D7	98
#define _Dis7	99
#define _E7	100
#define _F7	101
#define _Fis7	102
#define _G7	103
#define _Gis7	104
#define _A7	105
#define _Ais7	106
#define _H7	107
#define _C8	108
#define _Cis8	109
#define _D8	110
#define _Dis8	111
#define _E8	112
#define _F8	113
#define _Fis8	114
#define _G8	115
#define _Gis8	116
#define _A8	117
#define _Ais8	118
#define _H8	119
#define _C9	120
#define _Cis9	121
#define _D9	122
#define _Dis9	123
#define _E9	124
#define _F9	125
#define _Fis9	126
#define _G9	127