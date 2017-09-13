#include <iostream>
#include <cstdlib>

#include "../include/f_driver.hpp"

int
main (const int argc, const char **argv) {
    if (argc != 2) {
        return (EXIT_FAILURE);
    }

    Fortran::Driver driver;
    driver.parse(argv[1]);
    driver.print(std::cout) << "\n";
    return (EXIT_SUCCESS);
}