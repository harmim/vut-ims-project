/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Work shift process implementation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#include <cstdio>
#include "WorkShift.hpp"
#include "WorkShiftTimer.hpp"
#include "Car.hpp"
#include "AverageUniformDistribution.hpp"


WorkShift::WorkShift(
	unsigned long cars, double foodAverage, double foodDeviation
)
{
	this->cars = new Store("Car store", cars);

	// Round number of food to be divisible by car capacity.
	food = new unsigned long(static_cast<unsigned long>(
		AverageUniformDistribution::generate(foodAverage, foodDeviation)
	));
	unsigned long remainder = *food % Car::CAR_CAPACITY;
	if (remainder < Car::CAR_CAPACITY / 2.0)
	{
		*food -= remainder;
	}
	else
	{
		*food += Car::CAR_CAPACITY - remainder;
	}

	carLoadingStat = new Stat("Car loading duration");
	carRideStat = new Stat("Car ride duration");
	carRideDistanceStat = new Stat("Car ride distance");
	carRideConsumptionStat = new Stat("Car ride consumption");

	printStartOfShift();
}


WorkShift::~WorkShift()
{
	printEndOfShift();

	delete food;
	delete carLoadingStat;
	delete carRideStat;
	delete carRideDistanceStat;
	delete carRideConsumptionStat;
}


void WorkShift::Behavior()
{
	auto *workShiftTimer = new WorkShiftTimer(this);

	// While there is food left and there is free car, take it and start
	// car process.
	while (*food > 0)
	{
		Enter(*cars, 1);

		// If food has been taken during waiting for car, leave the car.
		if (*food == 0)
		{
			Leave(*cars, 1);
			break;
		}

		*food -= Car::CAR_CAPACITY;

		// Start car process.
		(new Car(
			cars,
			carLoadingStat,
			carRideStat,
			carRideDistanceStat,
			carRideConsumptionStat
		))->Activate();
	}

	// Wait for all cars and then end the work shift.
	Enter(*cars, cars->Capacity());
	Leave(*cars, cars->Capacity());

	delete workShiftTimer;
}


void WorkShift::printStartOfShift()
{
	printf("////////////////////////////////////////////////////////////\n\n");
	printf("Work shift started.\n");
	printf("\tStart time: %g.\n", Time);
	printf("\tNumber of cars: %lu.\n", cars->Capacity());
	printf("\tNumber of food: %lu.\n", *food);
	printf("\n");
}


void WorkShift::printEndOfShift()
{
	printf("End of work shift.\n");
	printf("\tEnd time: %g.\n", Time);
	printf("\tNumber of food left: %lu.\n", *food);
	printf("\tTotal car ride distance: %g.\n", carRideDistanceStat->Sum());
	printf(
		"\tTotal cars consumption: %g.\n",
		carRideDistanceStat->Sum() / 100.0 * Car::CAR_CONSUMPTION
	);
	printf("\n");
	cars->Output();
	carLoadingStat->Output();
	carRideStat->Output();
	carRideDistanceStat->Output();
	carRideConsumptionStat->Output();
	printf("////////////////////////////////////////////////////////////\n");
}
