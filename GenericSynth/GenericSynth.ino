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

//Not used by this sketch but dependant on one 
#include "Wire.h"

//Globals
uint32_t maxTimer = 60000000;
uint32_t maxInterval = 2000000;


#define LEDPIN 13
#include "timerModule32.h"
#include "stdint.h"
#include "PanelComponents.h"
#include "KnobPanel.h"  // added in Lesson 3
#include "proto-8Hardware.h"  // added in Lesson 4

KnobPanel myCustomPanel; // added in Lesson 3

IntervalTimer myTimer; //Interrupt for Teensy

//**Copy to make a new timer******************//  
//TimerClass32 usTimerA( 20000 ); //20 ms

//**Current list of timers********************//

TimerClass32 debugTimer( 1000000 ); //1 second
TimerClass32 serialTimer( 500000 ); // 0.5 seconds
TimerClass32 panelTimer( 5000 ); //5ms

// added in Lesson 4
TimerClass32 LEDsTimer( 20 ); // 20 uS
TimerClass32 switchesTimer( 500 ); // 500 uS
TimerClass32 knobsTimer( 500 ); // 500 uS

//components

//Simple8BitKnob myKnob;  // used in Lesson 2
//Windowed10BitKnob myKnob; // used in Lesson 2

// added in Lesson 4
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

void setup()
{
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
  
  // initialize IntervalTimer
  myTimer.begin(serviceUS, 1);  // serviceMS to run every 0.000001 seconds
  myCustomPanel.reset();  // added in Lesson 3

// added in Lesson 4
  LEDs.begin();
  knobs.begin();
  switches.begin();


//  myKnob.setHardware( new ArduinoAnalogIn( A2 ));  // used in Lesson 2

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
//        knobTimer.update(usTicks);
        // added in Lesson 4
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
      Serial.println("panel timer pending");
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

        //User code
/*    myKnob.freshen(5);  // Used in Lesson 2
 		  if(myKnob.serviceChanged())
		  {
			Serial.println(myKnob.getState());
		  }
*/		  
    
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
