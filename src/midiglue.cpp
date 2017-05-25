/*
  MIDI.cpp - MIDI library for Midi-Gnusbuino
  Copyright (c) 2012 Michael Egger, me@anyma.ch

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

/******************************************************************************
 * Includes
 ******************************************************************************/

#include "Arduino.h"
#include "midiglue.h"

/*void MIDIClass::begin(unsigned char mode){
	_analog_midi_thru = mode;
	if (mode) {
		Serial.begin(31250);
	}
}
*/

void MIDIClass::write(unsigned char command, unsigned char pitch,unsigned char velocity, unsigned char channel){
	if (channel > 0) channel--;
	channel %= 16;
	midiEventPacket_t event = {command >> 4, command | channel, pitch, velocity};
  	MidiUSB.sendMIDI(event);
	MidiUSB.flush();
}

unsigned char MIDIClass::read(MIDIMessage* msg) {
 	midiEventPacket_t rx;
    rx = MidiUSB.read();

    if (rx.header != 0) {
    	Serial.begin(31250);
		Serial.write(rx.header);		
		Serial.write(rx.byte2);
		Serial.write(rx.byte3);
		
		msg->command 	= rx.header << 4;
   		msg->channel	= (rx.byte1 & 0x0F) + 1;
   		msg->key		= rx.byte2;
      	msg->value		= rx.byte3;
      	return 1;			
	} else {
		return 0;
	}
}

void MIDIClass::sendMIDI(void) {
	MidiUSB.flush();
}
	

void MIDIClass::flush(void) {
 	MidiUSB.flush();
}







