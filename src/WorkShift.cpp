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
	unsigned long cars,
	double foodAverage,
	double foodDeviation,
	unsigned long carCapacity
): carCapacity(carCapacity)
{
	this->cars = new Store("Auta", cars);

	food = new unsigned long(static_cast<unsigned long>(
		AverageUniformDistribution::generate(foodAverage, foodDeviation)
	));
	unsigned long remainder = *food % carCapacity;
	if (remainder < carCapacity / 2.0)
	{
		*food -= remainder;
	}
	else
	{
		*food += carCapacity - remainder;
	}

	foodHistogram = new Histogram("Jidlo k rozvozu", 0.0, 500.0, 20);
}


WorkShift::~WorkShift()
{
	cars->Output();
	foodHistogram->Output();

	delete foodHistogram;
	delete food;
}


void WorkShift::Behavior()
{
	auto *workShiftTimer = new WorkShiftTimer(this);

	while (*food > 0)
	{
		Enter(*cars, 1);

		if (*food == 0)
		{
			Leave(*cars, 1);
			break;
		}

		printf("Cas: % g\n", Time);
		printf("Pocet jidel na sklade: %lu\n\n", *food);
		(*foodHistogram)(*food);

		(new Car(cars, food, carCapacity))->Activate();
	}

	Enter(*cars, cars->Capacity());
	Leave(*cars, cars->Capacity());

	delete workShiftTimer;
}
