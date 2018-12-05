/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Car process interface.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#ifndef IMS_PROJECT_CAR_HPP
#define IMS_PROJECT_CAR_HPP


#include <simlib.h>


class Car : public Process
{
public:
	/**
	 * Creates car process.
	 *
	 * @param cars Car store pointer.
	 * @param food Number of food to be distributed pointer.
	 * @param carCapacity Car food capacity.
	 */
	Car(Store *cars, unsigned long *food, unsigned long carCapacity);

	/**
	 * Car process behaviour.
	 */
	void Behavior() override;

private:
	/**
	 * Car loading duration.
	 */
	const double CAR_LOADING_DURATION_AVERAGE = 20.0; // in minutes
	const double CAR_LOADING_DURATION_DEVIATION = 10.0; // in percentage

	/**
	 * Car ride duration.
	 */
	const double CAR_RIDE_DURATION_AVERAGE = 2.0 * 60.0; // in minutes (2 h)
	const double CAR_RIDE_DURATION_DEVIATION = 20.0; // in percentage

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
};


#endif //IMS_PROJECT_CAR_HPP
