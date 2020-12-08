#include "vex.h"

using namespace vex;

void chassisLF_set(int input)
{
  chassisLF.spin(directionType::fwd, input, percentUnits::pct);
}
void chassisLB_set(int input)
{
  chassisLB.spin(directionType::fwd, input, percentUnits::pct);
}
void chassisRF_set(int input)
{
  chassisRF.spin(directionType::fwd, input, percentUnits::pct);
}
void chassisRB_set(int input)
{
  chassisRB.spin(directionType::fwd, input, percentUnits::pct);
}
void intakeL_set(int input)
{
  intakeL.spin(directionType::fwd, input, percentUnits::pct);
}
void intakeR_set(int input)
{
  intakeR.spin(directionType::fwd, input, percentUnits::pct);
}
void rollerT_set(int input)
{
  rollerT.spin(directionType::fwd, input, percentUnits::pct);
}
void rollerB_set(int input)
{
  rollerB.spin(directionType::fwd, input, percentUnits::pct);
}

void chassisL_set(int input)
{
  chassisLF_set(input);
  chassisLB_set(input);
}
void chassisR_set(int input)
{
  chassisRF_set(input);
  chassisRB_set(input);
}

void intake_set(int input)
{
  intakeL_set(input);
  intakeR_set(input);
}

void roller_set(int input)
{
  rollerT_set(input);
  rollerB_set(input);
}

// speed multiplier
double chassis_speed_multiplier = 0.8;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  while (true)
  {
    // speed multiplier control
    if (ctlr1.ButtonR1.pressing())
    {
      chassis_speed_multiplier = 1.0;
    }
    else if (ctlr1.ButtonR2.pressing())
    {
      chassis_speed_multiplier = 0.4;
    }
    else
    {
      chassis_speed_multiplier = 0.8;
    }

    // basic tank drive
    chassisL_set(ctlr1.Axis3.value() * chassis_speed_multiplier);
    chassisR_set(ctlr1.Axis2.value() * chassis_speed_multiplier);

    // intake control
    if (ctlr1.ButtonL1.pressing())
    {
      intake_set(100);
    }
    else if (ctlr1.ButtonL2.pressing())
    {
      intake_set(-100);
    }
    else
    {
      intake_set(0);
    }

    // roller control
    if (ctlr1.ButtonUp.pressing())
    {
      roller_set(100);
    }
    else if (ctlr1.ButtonDown.pressing())
    {
      roller_set(-100);
    }
    else
    {
      roller_set(0);
    }

    task::sleep(20);
  }
}
