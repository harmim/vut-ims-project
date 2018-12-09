/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Average uniform distribution generator implementation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#include <simlib.h>
#include "AverageUniformDistribution.hpp"


double AverageUniformDistribution::Generate(double average, double deviation)
{
	double deviationValue = deviation / 100.0 * average;
	return Uniform(average - deviationValue, average + deviationValue);
}
