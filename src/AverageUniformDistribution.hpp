/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Average uniform distribution generator interface.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#ifndef IMS_PROJECT_AVERAGEUNIFORMDISTRIBUTION_HPP
#define IMS_PROJECT_AVERAGEUNIFORMDISTRIBUTION_HPP


class AverageUniformDistribution
{
public:
	/**
	 * Generates pseudorandom numbers according to uniform distribution,
	 * low limit and high limit is created from average value and
	 * deviation from this value.
	 *
	 * @param average Average value.
	 * @param deviation Deviation from average value in percentage.
	 * @return Generated value.
	 */
	static double Generate(double average, double deviation);
};


#endif //IMS_PROJECT_AVERAGEUNIFORMDISTRIBUTION_HPP
