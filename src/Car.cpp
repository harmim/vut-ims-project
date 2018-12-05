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
	Store *cars, unsigned long *food, unsigned long carCapacity
): cars(cars), food(food), carCapacity(carCapacity)
{
}


void Car::Behavior()
{
	*food -= carCapacity;

	Wait(AverageUniformDistribution::generate(
		CAR_LOADING_DURATION_AVERAGE, CAR_LOADING_DURATION_DEVIATION
	));

	Wait(AverageUniformDistribution::generate(
		CAR_RIDE_DURATION_AVERAGE, CAR_RIDE_DURATION_DEVIATION
	));

	Leave(*cars, 1);
}
