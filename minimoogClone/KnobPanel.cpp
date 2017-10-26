#include "KnobPanel.h"
#include "panelComponents.h"
#include "HardwareInterfaces.h"
#include <Arduino.h>
#include "proto-8PanelComponents.h"
#include "proto-8HardwareInterfaces.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

extern AudioControlSGTL5000 sgtl5000_1;

KnobPanel::KnobPanel( void )
{
//  Knobs
	
	A1Knob.setHardware(new Proto8AnalogIn( 1 ));
	A2Knob.setHardware(new Proto8AnalogIn( 2 ));
	A3Knob.setHardware(new Proto8AnalogIn( 3 ));
	A4Knob.setHardware(new Proto8AnalogIn( 4 ));
	A5Knob.setHardware(new Proto8AnalogIn( 5 ));
	A6Knob.setHardware(new Proto8AnalogIn( 6 ));
	A7Knob.setHardware(new Proto8AnalogIn( 7 ));
	A8Knob.setHardware(new Proto8AnalogIn( 8 ));
	
	add( &A1Knob );
	add( &A2Knob );
	add( &A3Knob );
	add( &A4Knob );
	add( &A5Knob );
	add( &A6Knob );
	add( &A7Knob );
	add( &A8Knob );
	
	B1Knob.setHardware(new Proto8AnalogIn( 9 ));
	B2Knob.setHardware(new Proto8AnalogIn( 10 ));
	B3Knob.setHardware(new Proto8AnalogIn( 11 ));
	B4Knob.setHardware(new Proto8AnalogIn( 12 ));
	B5Knob.setHardware(new Proto8AnalogIn( 13 ));
	B6Knob.setHardware(new Proto8AnalogIn( 14 ));
	
	add( &B1Knob );
	add( &B2Knob );
	add( &B3Knob );
	add( &B4Knob );
	add( &B5Knob );
	add( &B6Knob );

	C1Knob.setHardware(new Proto8AnalogIn( 17 ));
	C2Knob.setHardware(new Proto8AnalogIn( 18 ));
	C3Knob.setHardware(new Proto8AnalogIn( 19 ));
	C4Knob.setHardware(new Proto8AnalogIn( 20 ));
	C5Knob.setHardware(new Proto8AnalogIn( 21 ));
	C6Knob.setHardware(new Proto8AnalogIn( 22 ));
	
	add( &C1Knob );
	add( &C2Knob );
	add( &C3Knob );
	add( &C4Knob );
	add( &C5Knob );
	add( &C6Knob );

	D1Knob.setHardware(new Proto8AnalogIn( 25 ));
	D2Knob.setHardware(new Proto8AnalogIn( 26 ));
	D3Knob.setHardware(new Proto8AnalogIn( 27 ));
	D4Knob.setHardware(new Proto8AnalogIn( 28 ));
	D5Knob.setHardware(new Proto8AnalogIn( 29 ));
	D6Knob.setHardware(new Proto8AnalogIn( 30 ));
	
	add( &D1Knob );
	add( &D2Knob );
	add( &D3Knob );
	add( &D4Knob );
	add( &D5Knob );
	add( &D6Knob );
	
	Ext1.setHardware(new Proto8AnalogIn( 31 ));
	Ext2.setHardware(new Proto8AnalogIn( 32 ));
	
	add( &Ext1 );
	add( &Ext2 );
	
	// Buttons
	
	A1Button.setHardware(new Proto8DigitalIn( 1,1 ), 0);
	A2Button.setHardware(new Proto8DigitalIn( 2,1 ), 0);
	A3Button.setHardware(new Proto8DigitalIn( 3,1 ), 0);
	A4Button.setHardware(new Proto8DigitalIn( 4,1 ), 0);
	A5Button.setHardware(new Proto8DigitalIn( 5,1 ), 0);
	A6Button.setHardware(new Proto8DigitalIn( 6,1 ), 0);
	A7Button.setHardware(new Proto8DigitalIn( 7,1 ), 0);
	A8Button.setHardware(new Proto8DigitalIn( 8,1 ), 0);

	add( &A1Button );
	add( &A2Button );
	add( &A3Button );
	add( &A4Button );
	add( &A5Button );
	add( &A6Button );
	add( &A7Button );
	add( &A8Button );

	
	B1Button.setHardware(new Proto8DigitalIn( 1,2 ), 0);
	B2Button.setHardware(new Proto8DigitalIn( 2,2 ), 0);
	B3Button.setHardware(new Proto8DigitalIn( 3,2 ), 0);
	B4Button.setHardware(new Proto8DigitalIn( 4,2 ), 0);
	B5Button.setHardware(new Proto8DigitalIn( 5,2 ), 0);
	B6Button.setHardware(new Proto8DigitalIn( 6,2 ), 0);
	B7Button.setHardware(new Proto8DigitalIn( 7,2 ), 0);
	B8Button.setHardware(new Proto8DigitalIn( 8,2 ), 0);

	add( &B1Button );
	add( &B2Button );
	add( &B3Button );
	add( &B4Button );
	add( &B5Button );
	add( &B6Button );
	add( &B7Button );
	add( &B8Button );

	C1Button.setHardware(new Proto8DigitalIn( 1,3 ), 0);
	C2Button.setHardware(new Proto8DigitalIn( 2,3 ), 0);
	C3Button.setHardware(new Proto8DigitalIn( 3,3 ), 0);
	C4Button.setHardware(new Proto8DigitalIn( 4,3 ), 0);
	C5Button.setHardware(new Proto8DigitalIn( 5,3 ), 0);
	C6Button.setHardware(new Proto8DigitalIn( 6,3 ), 0);
	C7Button.setHardware(new Proto8DigitalIn( 7,3 ), 0);
	C8Button.setHardware(new Proto8DigitalIn( 8,3 ), 0);

	add( &C1Button );
	add( &C2Button );
	add( &C3Button );
	add( &C4Button );
	add( &C5Button );
	add( &C6Button );
	add( &C7Button );
	add( &C8Button );

	D1Button.setHardware(new Proto8DigitalIn( 1,3 ), 0);
	D2Button.setHardware(new Proto8DigitalIn( 2,3 ), 0);
	D3Button.setHardware(new Proto8DigitalIn( 3,3 ), 0);
	D4Button.setHardware(new Proto8DigitalIn( 4,3 ), 0);
	D5Button.setHardware(new Proto8DigitalIn( 5,3 ), 0);
	D6Button.setHardware(new Proto8DigitalIn( 6,3 ), 0);
	D7Button.setHardware(new Proto8DigitalIn( 7,3 ), 0);
	D8Button.setHardware(new Proto8DigitalIn( 8,3 ), 0);

	add( &D1Button );
	add( &D2Button );
	add( &D3Button );
	add( &D4Button );
	add( &D5Button );
	add( &D6Button );
	add( &D7Button );
	add( &D8Button );

   // LEDs

	ALed1.setHardware(new Proto8DigitalOut( 1 ), 0);
	ALed2.setHardware(new Proto8DigitalOut( 2 ), 0);
	ALed3.setHardware(new Proto8DigitalOut( 3 ), 0);
	ALed4.setHardware(new Proto8DigitalOut( 4 ), 0);
	ALed5.setHardware(new Proto8DigitalOut( 5 ), 0);
	ALed6.setHardware(new Proto8DigitalOut( 6 ), 0);
	ALed7.setHardware(new Proto8DigitalOut( 7 ), 0);
	ALed8.setHardware(new Proto8DigitalOut( 8 ), 0);
	ALed9.setHardware(new Proto8DigitalOut( 9 ), 0);
	ALed10.setHardware(new Proto8DigitalOut( 10 ), 0);
	ALed11.setHardware(new Proto8DigitalOut( 11 ), 0);
	ALed12.setHardware(new Proto8DigitalOut( 12 ), 0);
	ALed13.setHardware(new Proto8DigitalOut( 13 ), 0);
	ALed14.setHardware(new Proto8DigitalOut( 14 ), 0);
	ALed15.setHardware(new Proto8DigitalOut( 15 ), 0);
	ALed16.setHardware(new Proto8DigitalOut( 16 ), 0);

	add( &ALed1 );
	add( &ALed2 );
	add( &ALed3 );
	add( &ALed4 );
	add( &ALed5 );
	add( &ALed6 );
	add( &ALed7 );
	add( &ALed8 );
	add( &ALed9 );
	add( &ALed10 );
	add( &ALed11 );
	add( &ALed12 );
	add( &ALed13 );
	add( &ALed14 );
	add( &ALed15 );
	add( &ALed16 );

	BLed1.setHardware(new Proto8DigitalOut( 17 ), 0);
	BLed2.setHardware(new Proto8DigitalOut( 18 ), 0);
	BLed3.setHardware(new Proto8DigitalOut( 19 ), 0);
	BLed4.setHardware(new Proto8DigitalOut( 20 ), 0);
	BLed5.setHardware(new Proto8DigitalOut( 21 ), 0);
	BLed6.setHardware(new Proto8DigitalOut( 22 ), 0);
	BLed7.setHardware(new Proto8DigitalOut( 23 ), 0);
	BLed8.setHardware(new Proto8DigitalOut( 24 ), 0);
	BLed9.setHardware(new Proto8DigitalOut( 25 ), 0);
	BLed10.setHardware(new Proto8DigitalOut( 26 ), 0);
	BLed11.setHardware(new Proto8DigitalOut( 27 ), 0);
	BLed12.setHardware(new Proto8DigitalOut( 28 ), 0);
	BLed13.setHardware(new Proto8DigitalOut( 29 ), 0);
	BLed14.setHardware(new Proto8DigitalOut( 30 ), 0);
	BLed15.setHardware(new Proto8DigitalOut( 31 ), 0);
	BLed16.setHardware(new Proto8DigitalOut( 32 ), 0);

	add( &BLed1 );
	add( &BLed2 );
	add( &BLed3 );
	add( &BLed4 );
	add( &BLed5 );
	add( &BLed6 );
	add( &BLed7 );
	add( &BLed8 );
	add( &BLed9 );
	add( &BLed10 );
	add( &BLed11 );
	add( &BLed12 );
	add( &BLed13 );
	add( &BLed14 );
	add( &BLed15 );
	add( &BLed16 );
	
	CLed1.setHardware(new Proto8DigitalOut( 49 ), 0);
	CLed2.setHardware(new Proto8DigitalOut( 50 ), 0);
	CLed3.setHardware(new Proto8DigitalOut( 51 ), 0);
	CLed4.setHardware(new Proto8DigitalOut( 52 ), 0);
	CLed5.setHardware(new Proto8DigitalOut( 53 ), 0);
	CLed6.setHardware(new Proto8DigitalOut( 54 ), 0);
	CLed7.setHardware(new Proto8DigitalOut( 55 ), 0);
	CLed8.setHardware(new Proto8DigitalOut( 56 ), 0);
	CLed9.setHardware(new Proto8DigitalOut( 57 ), 0);
	CLed10.setHardware(new Proto8DigitalOut( 58 ), 0);
	CLed11.setHardware(new Proto8DigitalOut( 59 ), 0);
	CLed12.setHardware(new Proto8DigitalOut( 60 ), 0);
	CLed13.setHardware(new Proto8DigitalOut( 61 ), 0);
	CLed14.setHardware(new Proto8DigitalOut( 62 ), 0);
	CLed15.setHardware(new Proto8DigitalOut( 63 ), 0);
	CLed16.setHardware(new Proto8DigitalOut( 64 ), 0);

	add( &CLed1 );
	add( &CLed2 );
	add( &CLed3 );
	add( &CLed4 );
	add( &CLed5 );
	add( &CLed6 );
	add( &CLed7 );
	add( &CLed8 );
	add( &CLed9 );
	add( &CLed10 );
	add( &CLed11 );
	add( &CLed12 );
	add( &CLed13 );
	add( &CLed14 );
	add( &CLed15 );
	add( &CLed16 );

	state = PInit;
}

void KnobPanel::reset( void )
{
	state = PInit;
	
}

void KnobPanel::tickStateMachine( int msTicksDelta )
{
	freshenComponents( msTicksDelta );

	//***** PROCESS THE LOGIC *****//
	//Now do the states.
	PStates nextState = state;
	switch( state )
	{
	case PInit:
		nextState = PRun;
		break;
	case PRun:
		if( A1Knob.serviceChanged() )  // Master Volume
		{
			Serial.print("knob A-1: ");
			Serial.println(A1Knob.getState());
			sgtl5000_1.volume((float)A1Knob.getState()/1024);
		}

		if( B1Knob.serviceChanged() )
		{
			Serial.print("knob B-1: ");
			Serial.println(B1Knob.getState());
		}

		if( C1Knob.serviceChanged() )
		{
			Serial.print("knob C-1: ");
			Serial.println(C1Knob.getState());
		}

		if( A1Button.serviceRisingEdge() )
		{
			Serial.println("Button A-1: pressed");
			ALed1.setState(LEDON);
			Serial.println("Turn ON ALed-1 ");
		}

		if( A2Button.serviceRisingEdge() )
		{
			Serial.println("Button A-2: pressed");
			ALed1.setState(LEDOFF);
			Serial.println("Turn Off ALed-1 ");
		}

		break;
	default:
		nextState = PInit;
		break;
	}
	state = nextState;

}
