//Header
#ifndef KNOBPANEL_H_INCLUDED
#define KNOBPANEL_H_INCLUDED

#include "Panel.h"
#include "PanelComponents.h"
#include "HardwareInterfaces.h"
#include <Arduino.h>


enum PStates
{
	PInit,
	PRun,
};

class KnobPanel : public Panel
{
public:
	KnobPanel( void );
	void reset( void );
	void tickStateMachine( int msTicksDelta );
	
private:
	//Internal Panel Components
	Windowed10BitKnob A1Knob;
	Windowed10BitKnob A2Knob;
	Windowed10BitKnob A3Knob;
	Windowed10BitKnob A4Knob;
	Windowed10BitKnob A5Knob;
	Windowed10BitKnob A6Knob;
	Windowed10BitKnob A7Knob;
	Windowed10BitKnob A8Knob;

	//State machine stuff  
	PStates state;

};



#endif