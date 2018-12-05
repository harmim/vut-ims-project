/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Work shift timer event implementation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#include "WorkShiftTimer.hpp"


WorkShiftTimer::WorkShiftTimer(WorkShift *workShift): workShift(workShift)
{
	Activate(Time + WORK_SHIFT_DURATION);
}


void WorkShiftTimer::Behavior()
{
	delete workShift;
}
