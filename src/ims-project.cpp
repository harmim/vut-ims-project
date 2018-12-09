/**
 * VUT FIT IMS project - Freshbox food distribution.
 *
 * @file Main file, simulation initialization, start of simulation.
 * @author Dominik Harmim <xharmi00@stud.fit.vutbr.cz>
 * @author Vojtech Hertl <xhertl04@stud.fit.vutbr.cz>
 */


#include <cstdlib>
#include <simlib.h>
#include <getopt.h>
#include <iostream>
#include "WorkShift.hpp"


#define SIMULATION_START_TIME 0.0
#define SIMULATION_END_TIME 24.0 * 60.0

#define DEFAULT_NUMBER_OF_CARS 16
#define DEFAULT_AVERAGE_NUMBER_OF_FOOD 21200.0
#define DEFAULT_DEVIATION_FROM_NUMBER_OF_FOOD 4.7


using namespace std;


void PrintHelp()
{
	cerr << "Possible arguments:\n"
		<< "\t-c or --cars to specify the number of cars\n"
		<< "\t-f or --food to specify the number of food\n";
}


int main(int argc, char *argv[])
{
	unsigned long cars = DEFAULT_NUMBER_OF_CARS;
	double food = DEFAULT_AVERAGE_NUMBER_OF_FOOD;

	int opt;
	char *err;
	static const char *sOpts = "c:f:";
	static const struct option lOpts[] = {
		{"cars", required_argument, nullptr, 'c'},
		{"food", required_argument, nullptr, 'f'},
		{nullptr, 0, nullptr, 0},
	};

	while ((opt = getopt_long(argc, argv, sOpts, lOpts, nullptr)) != -1)
	{
		switch (opt)
		{
			case 0:
				break;

			case 'c':
				cars = strtoul(optarg, &err, 10);

				if (*err != '\0')
				{
					cerr << "Number of cars must be a positive integer.\n";
					return EXIT_FAILURE;
				}

				break;

			case 'f':
				food = strtod(optarg, &err);

				if (*err != '\0')
				{
					cerr << "Number of food must be a positive number.\n";
					return EXIT_FAILURE;
				}

				if (food < 0)
				{
					cerr << "Number of food must be a positive number.\n";
					return EXIT_FAILURE;
				}

				break;

			case '?':
			default:
				PrintHelp();
				return EXIT_FAILURE;
		}
	}

	if (optind < argc)
	{
		PrintHelp();
		return EXIT_FAILURE;
	}

	cout << "------------------------------------------------------------\n"
		<< "START OF SIMULATION\n"
		<< "------------------------------------------------------------\n"
		<< "Running experiment with " << cars << " number of cars.\n"
		<< "Running experiment with " << food << " average number of food.\n"
		<< "------------------------------------------------------------\n"
		<< endl;

	for (int i = 1; i <= 5; i++)
	{
		cout << "----- RUNNING TRY NUMBER " << i << ".\n";

		Init(SIMULATION_START_TIME, SIMULATION_END_TIME);
		(new WorkShift(
			cars,
			food,
			DEFAULT_DEVIATION_FROM_NUMBER_OF_FOOD
		))->Activate();
		Run();
		SIMLIB_statistics.Output();

		cout << "----- END OF TRY NUMBER " << i << ".\n\n";
	}

	cout << "------------------------------------------------------------\n"
		<< "SIMULATION FINISHED\n"
		<< "------------------------------------------------------------\n";

	return EXIT_SUCCESS;
}
