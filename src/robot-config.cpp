#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller ctlr1;

#define _PRACTICE_BOT_
#ifndef _PRACTICE_BOT_

// main bot
motor chassisLF  = motor(PORT1, false);
motor chassisLB  = motor(PORT9, true);
motor chassisRF = motor(PORT5, true);
motor chassisRB = motor(PORT8, false);

#else

// practice bot
motor chassisLF  = motor(PORT1, false);
motor chassisLB  = motor(PORT13, false);
motor chassisRF = motor(PORT9, true);
motor chassisRB = motor(PORT18, true);

#endif

motor intakeL = motor(PORT20, false);
motor intakeR = motor(PORT7, true);

motor rollerT = motor(PORT11, true);
motor rollerB = motor(PORT16, true);

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}