/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Car process implementation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#include "Car.hpp"
#include "AverageUniformDistribution.hpp"


Car::Car(
	Store *cars,
	unsigned long *food,
	Stat *carLoadingStat,
	Stat *carRideStat,
	Stat *carRideDistanceStat,
	Stat *carRideConsumptionStat
) :
	cars(cars),
	food(food),
	carLoadingStat(carLoadingStat),
	carRideStat(carRideStat),
	carRideDistanceStat(carRideDistanceStat),
	carRideConsumptionStat(carRideConsumptionStat)
{
}


void Car::Behavior()
{
	*food -= CAR_CAPACITY;

	double carLoadingDuration = AverageUniformDistribution::generate(
		CAR_LOADING_DURATION_AVERAGE, CAR_LOADING_DURATION_DEVIATION
	);
	(*carLoadingStat)(carLoadingDuration);
	Wait(carLoadingDuration);

	double carRideDuration = AverageUniformDistribution::generate(
		CAR_RIDE_DURATION_AVERAGE, CAR_RIDE_DURATION_DEVIATION
	);
	(*carRideStat)(carRideDuration);
	Wait(carRideDuration);

	double carRideDistance = AverageUniformDistribution::generate(
		CAR_RIDE_DISTANCE_AVERAGE, CAR_RIDE_DISTANCE_DEVIATION
	);
	(*carRideDistanceStat)(carRideDistance);
	(*carRideConsumptionStat)(carRideDistance / 100.0 * CAR_CONSUMPTION);

	Leave(*cars, 1);
}