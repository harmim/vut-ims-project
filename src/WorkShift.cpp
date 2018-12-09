/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Work shift process implementation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#include <iostream>
#include "WorkShift.hpp"
#include "WorkShiftTimer.hpp"
#include "Car.hpp"
#include "AverageUniformDistribution.hpp"


using namespace std;


WorkShift::WorkShift(
	unsigned long cars, double foodAverage, double foodDeviation
)
{
	this->cars = new Store("Car store", cars);

	// Round number of food to be divisible by car capacity.
	food = new unsigned long(static_cast<unsigned long>(
		AverageUniformDistribution::Generate(foodAverage, foodDeviation)
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

	PrintStartOfShift();
}


WorkShift::~WorkShift()
{
	PrintEndOfShift();

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


void WorkShift::PrintStartOfShift()
{
	cout << "////////////////////////////////////////////////////////////\n"
		<< "Work shift started.\n"
		<< "\tStart time: " << Time << ".\n"
		<< "\tNumber of cars: " << cars->Capacity() << ".\n"
		<< "\tNumber of food: " << *food << ".\n"
		<< endl;
}


void WorkShift::PrintEndOfShift()
{
	cout << "End of work shift.\n"
		<< "\tEnd time: " << Time << ".\n"
		<< "\tNumber of food left: " << *food << ".\n"
		<< "\tTotal car ride distance: " << carRideDistanceStat->Sum() << ".\n"
		<< "\tTotal cars consumption: "
			<< carRideDistanceStat->Sum() / 100.0 * Car::CAR_CONSUMPTION
			<< ".\n"
		<< endl;

	cars->Output();
	carLoadingStat->Output();
	carRideStat->Output();
	carRideDistanceStat->Output();
	carRideConsumptionStat->Output();

	cout << "////////////////////////////////////////////////////////////\n";
}
