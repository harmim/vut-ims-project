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


int main(int argc, char *argv[]) {
    int c;
    unsigned int cars = 16;
    double food = 21200.0;
    char *err = nullptr;

    while (1) {
        static struct option longOptions[] = {
                {"cars", required_argument, 0, 'c'},
                {"food", required_argument, 0, 'f'},
                {0, 0, 0, 0}
        };


        c = getopt_long(argc, argv, "c:f:", longOptions, nullptr);

        if (c == -1)
            break;

        switch (c) {
            case 0:
                break;

            case 'c':
                cars = strtoul(optarg, &err, 10);

                if (*err != '\0') {
                    std::cerr << "Number of cars must be a positive integer." << std::endl;
                    return EXIT_FAILURE;
                }

                break;

            case 'f':
                food = strtod(optarg, &err);

                if (*err != '\0') {
                    std::cerr << "Number of food must be a positive number." << std::endl;
                    return EXIT_FAILURE;
                }

                if (food < 0) {
                    std::cerr << "Number of food must be a positive number." << std::endl;
                    return EXIT_FAILURE;
                }

                break;

            case '?':
                std::cerr << "Two arguments are required:" << std::endl <<
                          "-c or --cars to specify the number of cars" << std::endl <<
                          "-f or --food to specify the number of food" << std::endl;
                return EXIT_FAILURE;

            default:
                std::cerr << "Two arguments are required:" << std::endl <<
                          "-c or --cars to specify the number of cars" << std::endl <<
                          "-f or --food to specify the number of food" << std::endl;
                return EXIT_FAILURE;
        }
    }

    if (optind < argc) {
        std::cerr << "Two arguments are required:" << std::endl <<
                  "-c or --cars to specify the number of cars" << std::endl <<
                  "-f or --food to specify the number of food" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "START OF SIMULATION" << std::endl;
    std::cout << "////////////////////////////////////////////////////////////" << std::endl;
    std::cout << "Running experiment with " << cars << " number of cars." << std::endl;
    std::cout << "Running experiment with " << food << " average number of food." << std::endl;
    std::cout << "////////////////////////////////////////////////////////////" << std::endl;


    for (int i = 1; i <= 5; i++) {
        std::cout << "RUNNING TRY NUMBER " << i << "." << std::endl;
        Init(0.0, 24.0 * 60.0);
        (new WorkShift(cars, food, 4.7))->Activate();
        Run();
        SIMLIB_statistics.Output();
        std::cout << "////////////////////////////////////////////////////////////" << std::endl;
        std::cout << "END OF TRY NUMBER " << i << "." << std::endl;
        std::cout << "////////////////////////////////////////////////////////////" << std::endl;
    }

    std::cout << "SIMULATION FINISHED" << std::endl;
    std::cout << "////////////////////////////////////////////////////////////" << std::endl;
    return EXIT_SUCCESS;

}
