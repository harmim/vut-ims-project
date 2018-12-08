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
	 * Car fuel consumption.
	 */
	static constexpr double CAR_CONSUMPTION = 7.7; // l/100 km

	/**
	 * Creates car process.
	 *
	 * @param cars Car store.
	 * @param carLoadingStat Car loading duration statistics.
	 * @param carRideStat Car ride duration statistics.
	 * @param carRideDistanceStat Car ride distance statistics.
	 * @param carRideConsumptionStat Car ride fuel consumption statistics.
	 */
	Car(
		Store *cars,
		Stat *carLoadingStat,
		Stat *carRideStat,
		Stat *carRideDistanceStat,
		Stat *carRideConsumptionStat
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
	const double CAR_LOADING_DURATION_DEVIATION = 27.1; // in percentage

	/**
	 * Car ride duration.
	 */
	const double CAR_RIDE_DURATION_AVERAGE = 97.0; // in minutes
	const double CAR_RIDE_DURATION_DEVIATION = 12.4; // in percentage

	/**
	 * Car ride distance.
	 */
	const double CAR_RIDE_DISTANCE_AVERAGE = 43.0; // in km
	const double CAR_RIDE_DISTANCE_DEVIATION = 18.6; // in perentage

	/**
	 * Car store.
	 */
	Store *cars;

	/**
	 * Car loading duration statistics.
	 */
	Stat *carLoadingStat;

	/**
	 * Car ride duration statistics.
	 */
	Stat *carRideStat;

	/**
	 * Car ride distance statistics.
	 */
	Stat *carRideDistanceStat;

	/**
	 * Car ride fuel consumption statistics.
	 */
	Stat *carRideConsumptionStat;
};


#endif //IMS_PROJECT_CAR_HPP
