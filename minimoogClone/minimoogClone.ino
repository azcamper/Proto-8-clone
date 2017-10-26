//HOW TO OPERATE
//  Make TimerClass objects for each thing that needs periodic service
//  pass the interval of the period in ticks
//
//  Set maxInterval to rollover rate
//  Set maxTimer to the max foreseen interval of any timer.
//  maxTimer + maxInterval = max countable value.

//NOTICE:
//  The timerModule32 only works on teensy / fast processors.  It works the same
//  but keeps track of everything in us counts.


//Globals
uint32_t maxTimer = 60000000;
uint32_t maxInterval = 2000000;


#define LEDPIN 13
#include "timerModule32.h"
#include "stdint.h"
#include "PanelComponents.h"
#include "mmCPanel.h"
#include "proto-8Hardware.h"
#include "HardwareInterfaces.h"
//#include "P8Interface.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=444,299
AudioOutputI2S           i2s1;           //xy=718,298
AudioConnection          patchCord1(sine1, 0, i2s1, 0);
AudioConnection          patchCord2(sine1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=453,444
// GUItool: end automatically generated code


mmCPanel myCustomPanel;

IntervalTimer myTimer; //Interrupt for Teensy

//**Copy to make a new timer******************//  
//TimerClass32 usTimerA( 20000 ); //20 ms

//**Current list of timers********************//

TimerClass32 midiRecordTimer( 1000 );
TimerClass32 debugTimer( 1000000 ); //1 second
TimerClass32 serialTimer( 500000 ); // 0.5 seconds
TimerClass32 panelTimer( 5000 ); //5ms


TimerClass32 LEDsTimer( 20 ); // 20 uS
TimerClass32 switchesTimer( 500 ); // 500 uS
TimerClass32 knobsTimer( 500 ); // 500 uS
//**Panel State Machine***********************//


volatile int32_t pUTStartTime = 0;
volatile int32_t pUTLastTime = 0;
volatile int32_t pUTStopTime = 0;
volatile int32_t pUTLength = 0;

// MIDI things
#include <MIDI.h>
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, midiA);

//components

LEDShiftRegister LEDs;
AnalogMuxTree knobs;
SwitchMatrix switches;


//Note on TimerClass-
//Change with usTimerA.setInterval( <the new interval> );

uint32_t usTicks = 0;

//  The lock works like this:
//
//    When the interrupt fires, the lock is removed.  Now
//    the main free-wheeling loop can update the change to
//    the timerModules.  Once complete, the lock is replaced
//    so that it can't update more than once per firing
//    of the interrupt

uint8_t usTicksLocked = 1; //start locked out

void handleNoteOn(byte channel, byte pitch, byte velocity) 
{ 
	Serial.print("Note On :"); 
	Serial.print("0x"); 
	Serial.print(channel, HEX); 
	Serial.print(" 0x"); 
	Serial.print(pitch, HEX); 
	Serial.print(" 0x"); 
	Serial.print(velocity, HEX); 
	Serial.print("\n"); 
	myCustomPanel.CLed16.setState(LEDON);
} 

void handleNoteOff(byte channel, byte pitch, byte velocity) 
{ 
	Serial.print("Note Off:"); 
	Serial.print("0x"); 
	Serial.print(channel, HEX); 
	Serial.print(" 0x"); 
	Serial.print(pitch, HEX); 
	Serial.print(" 0x"); 
	Serial.print(velocity, HEX); 
	Serial.print("\n");
  myCustomPanel.CLed16.setState(LEDOFF);	
} 

void setup()
{
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  
  // initialize IntervalTimer
  myTimer.begin(serviceUS, 1);  // serviceMS to run every 0.000001 seconds
  myCustomPanel.reset();

  //**** Audio Section ****//
	AudioMemory(35);
	sine1.frequency(240);
	sine1.amplitude(1.0);
	sgtl5000_1.enable();
	sgtl5000_1.volume(0.5);

  LEDs.begin();
  knobs.begin();
  switches.begin();
  
//  pinMode(11, OUTPUT); 
	midiA.turnThruOn(); 
	midiA.setHandleNoteOn(handleNoteOn);  // Put only the name of the function 
	midiA.setHandleNoteOff(handleNoteOff); 
//	midiA.setHandlePitchBend(handlePitchBend); 
//	midiA.setHandleControlChange(handleControlChange); 
	 
	// Initiate MIDI communications, listen to all channels 
	midiA.begin(MIDI_CHANNEL_OMNI); 
	Serial.println("Starting program"); 


}

void loop()
{
	//Update the timers, but only once per interrupt
	if( usTicksLocked == 0 )
	{
		//**Copy to make a new timer******************//  
		//msTimerA.update(usTicks);
		
		debugTimer.update(usTicks);
		serialTimer.update(usTicks);
		panelTimer.update(usTicks);
		LEDsTimer.update(usTicks);
		switchesTimer.update(usTicks);
		knobsTimer.update(usTicks);
		
		//Done?  Lock it back up
		usTicksLocked = 1;
	}  //The ISR will unlock.

	//**Copy to make a new timer******************//  
	
	if(debugTimer.flagStatus() == PENDING)
	{
		//User code
		digitalWrite( LEDPIN, digitalRead( LEDPIN ) ^ 0x01 );
	}
	if(serialTimer.flagStatus() == PENDING)
	{
	   //User code
	   Serial.println("Hello Randy");
	}
    if(panelTimer.flagStatus() == PENDING)
    {
		//Tick the machine  added in Lesson 3
     	myCustomPanel.tickStateMachine(5);
    }
    
	if(LEDsTimer.flagStatus() == PENDING)
    {
		LEDs.send();
    }

    if(switchesTimer.flagStatus() == PENDING)
    {
		switches.scan();
    }

    if(knobsTimer.flagStatus() == PENDING)
    {
		knobs.scan();
    }
	    midiA.read();
   
}

void serviceUS(void)
{
  uint32_t returnVar = 0;
  if(usTicks >= ( maxTimer + maxInterval ))
  {
    returnVar = usTicks - maxTimer;
  }
  else
  {
    returnVar = usTicks + 1;
  }
  usTicks = returnVar;
  usTicksLocked = 0;  //unlock
}

