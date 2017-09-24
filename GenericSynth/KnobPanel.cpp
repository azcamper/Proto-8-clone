#include "KnobPanel.h"
#include "panelComponents.h"
#include "HardwareInterfaces.h"
#include <Arduino.h>
#include "proto-8PanelComponents.h"
#include "proto-8HardwareInterfaces.h"

KnobPanel::KnobPanel( void )
{
// removed and replaced in lesson 4
/*	myKnob1.setHardware(new ArduinoAnalogIn( A2 ));
	add( &myKnob1 );
	
	myKnob2.setHardware(new ArduinoAnalogIn( A3 ));
	add( &myKnob2 );
*/
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
	
	add( &B1Knob );
	add( &B2Knob );
	add( &B3Knob );
	add( &B4Knob );
	add( &B5Knob );

	C1Knob.setHardware(new Proto8AnalogIn( 17 ));
	C2Knob.setHardware(new Proto8AnalogIn( 18 ));
	C3Knob.setHardware(new Proto8AnalogIn( 19 ));
	C4Knob.setHardware(new Proto8AnalogIn( 20 ));
	C5Knob.setHardware(new Proto8AnalogIn( 21 ));
	
	add( &C1Knob );
	add( &C2Knob );
	add( &C3Knob );
	add( &C4Knob );
	add( &C5Knob );

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

   // LEDs

	ALed1.setHardware(new Proto8DigitalOut( 1 ), 0);
	ALed2.setHardware(new Proto8DigitalOut( 2 ), 0);
	ALed3.setHardware(new Proto8DigitalOut( 3 ), 0);
	ALed4.setHardware(new Proto8DigitalOut( 4 ), 0);
	ALed5.setHardware(new Proto8DigitalOut( 5 ), 0);
	ALed6.setHardware(new Proto8DigitalOut( 6 ), 0);
	ALed7.setHardware(new Proto8DigitalOut( 7 ), 0);
	ALed8.setHardware(new Proto8DigitalOut( 8 ), 0);

	add( &ALed1 );
	add( &ALed2 );
	add( &ALed3 );
	add( &ALed4 );
	add( &ALed5 );
	add( &ALed6 );
	add( &ALed7 );
	add( &ALed8 );

	BLed1.setHardware(new Proto8DigitalOut( 9 ), 0);
	BLed2.setHardware(new Proto8DigitalOut( 10 ), 0);
	BLed3.setHardware(new Proto8DigitalOut( 11 ), 0);
	BLed4.setHardware(new Proto8DigitalOut( 12 ), 0);
	BLed5.setHardware(new Proto8DigitalOut( 13 ), 0);
	BLed6.setHardware(new Proto8DigitalOut( 14 ), 0);
	BLed7.setHardware(new Proto8DigitalOut( 15 ), 0);
	BLed8.setHardware(new Proto8DigitalOut( 16 ), 0);

	add( &BLed1 );
	add( &BLed2 );
	add( &BLed3 );
	add( &BLed4 );
	add( &BLed5 );
	add( &BLed6 );
	add( &BLed7 );
	add( &BLed8 );
	
	CLed1.setHardware(new Proto8DigitalOut( 48 ), 0);
	CLed2.setHardware(new Proto8DigitalOut( 49 ), 0);
	CLed3.setHardware(new Proto8DigitalOut( 50 ), 0);
	CLed4.setHardware(new Proto8DigitalOut( 51 ), 0);
	CLed5.setHardware(new Proto8DigitalOut( 52 ), 0);
	CLed6.setHardware(new Proto8DigitalOut( 53 ), 0);
	CLed7.setHardware(new Proto8DigitalOut( 54 ), 0);
	CLed8.setHardware(new Proto8DigitalOut( 55 ), 0);

	add( &CLed1 );
	add( &CLed2 );
	add( &CLed3 );
	add( &CLed4 );
	add( &CLed5 );
	add( &CLed6 );
	add( &CLed7 );
	add( &CLed8 );

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
		if( A1Knob.serviceChanged() )
		{
			Serial.print("knob A-1: ");
			Serial.println(A1Knob.getState());
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
