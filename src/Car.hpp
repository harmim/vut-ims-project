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
	 * Car food capacity.
	 */
	static const unsigned long CAR_CAPACITY = 500;

	/**
	 * Creates car process.
	 *
	 * @param cars Car store.
	 * @param food Number of food to be distributed.
	 * @param carLoadingStat Car loading duration statistics.
	 * @param carRideStat Car ride duration statistics.
	 */
	Car(
		Store *cars,
		unsigned long *food,
		Stat *carLoadingStat,
		Stat *carRideStat
	);

	/**
	 * Car process behaviour.
	 */
	void Behavior() override;

private:
	/**
	 * Car loading duration.
	 */
	const double CAR_LOADING_DURATION_AVERAGE = 11.0; // in minutes
	const double CAR_LOADING_DURATION_DEVIATION = 27.1; // in percentage (3 min)

	/**
	 * Car ride duration.
	 */
	const double CAR_RIDE_DURATION_AVERAGE = 97.0; // in minutes
	const double CAR_RIDE_DURATION_DEVIATION = 12.4; // in percentage (12 min)

	/**
	 * Car store.
	 */
	Store *cars;

	/**
	 * Number of food to be distributed.
	 */
	unsigned long *food;

	/**
	 * Car loading duration statistics.
	 */
	Stat *carLoadingStat;

	/**
	 * Car ride duration statistics.
	 */
	Stat *carRideStat;
};


#endif //IMS_PROJECT_CAR_HPP
