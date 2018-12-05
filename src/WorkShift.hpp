/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Work shift process interface.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#ifndef IMS_PROJECT_WORKSHIFT_HPP
#define IMS_PROJECT_WORKSHIFT_HPP


#include <simlib.h>


class WorkShift : public Process
{
public:
	/**
	 * Creates work shift process.
	 *
	 * @param cars Number of cars.
	 * @param foodAverage Average number of food to be distributed.
	 * @param foodDeviation Deviation from average number of food.
	 * @param carCapacity Car food capacity.
	 */
	WorkShift(
		unsigned long cars,
		double foodAverage,
		double foodDeviation,
		unsigned long carCapacity
	);

	/**
	 * Desctructs work shift process.
	 */
	~WorkShift() override;

	/**
	 * Work shift process behavoir.
	 */
	void Behavior() override;

private:
	/**
	 * Car store pointer.
	 */
	Store *cars;

	/**
	 * Number of food to be distributed pointer.
	 */
	unsigned long *food;

	/**
	 * Car food capacity.
	 */
	unsigned long carCapacity;

	Histogram *foodHistogram;
};


#endif //IMS_PROJECT_WORKSHIFT_HPP
