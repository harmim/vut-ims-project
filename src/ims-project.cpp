/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Main file, simulation initialization, start of simulation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#include <cstdlib>
#include <simlib.h>

#include "WorkShift.hpp"


int main()
{
	Init(0.0, 24.0 * 60.0);
	(new WorkShift(16, 21200.0, 4.7))->Activate();
	Run();
	SIMLIB_statistics.Output();

	return EXIT_SUCCESS;
}
