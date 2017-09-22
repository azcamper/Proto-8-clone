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
	
	A1Knob.setHardware(new Proto8AnalogIn( 1 ));
	A2Knob.setHardware(new Proto8AnalogIn( 2 ));
	A3Knob.setHardware(new Proto8AnalogIn( 3 ));
	A3Knob.setHardware(new Proto8AnalogIn( 4 ));
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
	
	state = PInit;
}

void KnobPanel::reset( void )
{
	state = PInit;
	
}

void KnobPanel::tickStateMachine( int msTicksDelta )
{
    Serial.println("KnobPanel-1");
	freshenComponents( msTicksDelta );
    Serial.println("KnobPanel-2");

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
		if( A2Knob.serviceChanged() )

		{

			Serial.print("knob A-2: ");

			Serial.println(A2Knob.getState());

		}
			if( A3Knob.serviceChanged() )

		{

			Serial.print("knob A-3: ");

			Serial.println(A3Knob.getState());

		}

		break;
	default:
		nextState = PInit;
		break;
	}
	state = nextState;

}
