#include "KnobPanel.h"
#include "panelComponents.h"
#include "HardwareInterfaces.h"
#include <Arduino.h>

KnobPanel::KnobPanel( void )
{
	myKnob1.setHardware(new ArduinoAnalogIn( A2 ));
	add( &myKnob1 );
	
	myKnob2.setHardware(new ArduinoAnalogIn( A3 ));
	add( &myKnob2 );
	
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
		if( myKnob1.serviceChanged() )
		{
			Serial.println("knob 1");
			Serial.println(myKnob1.getState());
		}
		if( myKnob2.serviceChanged() )
		{
			Serial.println("knob 2");
			Serial.println(myKnob2.getState());
		}
	
		break;
	default:
		nextState = PInit;
		break;
	}
	state = nextState;

}
