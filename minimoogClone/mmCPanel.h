//Header
#ifndef MMCPANEL_H_INCLUDED
#define MMCPANEL_H_INCLUDED

#include "Panel.h"
#include "PanelComponents.h"
#include "HardwareInterfaces.h"
#include <Arduino.h>


enum PStates
{
	PInit,
	PRun,
};

class mmCPanel : public Panel
{
public:
	mmCPanel( void );
	void reset( void );
	void tickStateMachine( int msTicksDelta );
	
private:
	//Internal Panel Components
	Simple10BitKnob A1Knob;
	Simple10BitKnob A2Knob;
	Simple10BitKnob A3Knob;
	Simple10BitKnob A4Knob;
	Simple10BitKnob A5Knob;
	Simple10BitKnob A6Knob;
	Simple10BitKnob A7Knob;
	Simple10BitKnob A8Knob;
	
	Simple10BitKnob B1Knob;
	Simple10BitKnob B2Knob;
	Simple10BitKnob B3Knob;
	Simple10BitKnob B4Knob;
	Simple10BitKnob B5Knob;
	Simple10BitKnob B6Knob;
	
	Simple10BitKnob C1Knob;
	Simple10BitKnob C2Knob;
	Simple10BitKnob C3Knob;
	Simple10BitKnob C4Knob;
	Simple10BitKnob C5Knob;
	Simple10BitKnob C6Knob;

	Simple10BitKnob D1Knob;
	Simple10BitKnob D2Knob;
	Simple10BitKnob D3Knob;
	Simple10BitKnob D4Knob;
	Simple10BitKnob D5Knob;
	Simple10BitKnob D6Knob;
 
	Simple10BitKnob Ext1;
	Simple10BitKnob Ext2;
  
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

	Button D1Button;
	Button D2Button;
	Button D3Button;
	Button D4Button;
	Button D5Button;
	Button D6Button;
	Button D7Button;
	Button D8Button;


	Led ALed1;
	Led ALed2;
	Led ALed3;
	Led ALed4;
	Led ALed5;
	Led ALed6;
	Led ALed7;
	Led ALed8;
	Led ALed9;
	Led ALed10;
	Led ALed11;
	Led ALed12;
	Led ALed13;
	Led ALed14;
	Led ALed15;
	Led ALed16;

	Led BLed1;
	Led BLed2;
	Led BLed3;
	Led BLed4;
	Led BLed5;
	Led BLed6;
	Led BLed7;
	Led BLed8;
	Led BLed9;
	Led BLed10;
	Led BLed11;
	Led BLed12;
	Led BLed13;
	Led BLed14;
	Led BLed15;
	Led BLed16;
	
// CLeds are not implemented in this design

	Led DLed1;
	Led DLed2;
	Led DLed3;
	Led DLed4;
	Led DLed5;
	Led DLed6;
	Led DLed7;
	Led DLed8;
	Led DLed9;
	Led DLed10;
	Led DLed11;
	Led DLed12;
	Led DLed13;
	Led DLed14;
	Led DLed15;
public:	
	Led DLed16;

	//State machine stuff  
	PStates state;

};



#endif
