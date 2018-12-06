/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Work shift timer event interface.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#ifndef IMS_PROJECT_WORKSHIFTTIMER_HPP
#define IMS_PROJECT_WORKSHIFTTIMER_HPP


#include <simlib.h>
#include "WorkShift.hpp"


class WorkShiftTimer : public Event
{
public:
	/**
	 * Constructs work shift timer event.
	 *
	 * @param workShift Work shift process which will be killed
	 *                  after work shift duration.
	 */
	explicit WorkShiftTimer(WorkShift *workShift);

	/**
	 * Work shift timer event behavior.
	 */
	void Behavior() override;

private:
	/**
	 * Work shift duration in minutes (6 h).
	 */
	const double WORK_SHIFT_DURATION = 6.0 * 60.0;

	/**
	 * Work shift process which will be killed
	 * after work shift duration.
	 */
	WorkShift *workShift;

	/**
	 * Prints end of shift information.
	 */
	void printEndOfShift();
};


#endif //IMS_PROJECT_WORKSHIFTTIMER_HPP
