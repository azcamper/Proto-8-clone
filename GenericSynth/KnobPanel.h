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
	
	Windowed10BitKnob B1Knob;
	Windowed10BitKnob B2Knob;
	Windowed10BitKnob B3Knob;
	Windowed10BitKnob B4Knob;
	Windowed10BitKnob B5Knob;
	
	Windowed10BitKnob C1Knob;
	Windowed10BitKnob C2Knob;
	Windowed10BitKnob C3Knob;
	Windowed10BitKnob C4Knob;
	Windowed10BitKnob C5Knob;
	
	Button A1Button;
	Button A2Button;
	Button A3Button;
	Button A4Button;
	Button A5Button;
	Button A6Button;
	Button A7Button;
	Button A8Button;

	Button B1Button;
	Button B2Button;
	Button B3Button;
	Button B4Button;
	Button B5Button;
	Button B6Button;
	Button B7Button;
	Button B8Button;
	
	Button C1Button;
	Button C2Button;
	Button C3Button;
	Button C4Button;
	Button C5Button;
	Button C6Button;
	Button C7Button;
	Button C8Button;


	Led ALed1;
	Led ALed2;
	Led ALed3;
	Led ALed4;
	Led ALed5;
	Led ALed6;
	Led ALed7;
	Led ALed8;

	Led BLed1;
	Led BLed2;
	Led BLed3;
	Led BLed4;
	Led BLed5;
	Led BLed6;
	Led BLed7;
	Led BLed8;

	Led CLed1;
	Led CLed2;
	Led CLed3;
	Led CLed4;
	Led CLed5;
	Led CLed6;
	Led CLed7;
	Led CLed8;

	//State machine stuff  
	PStates state;

};



#endif