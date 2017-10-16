#include <iostream>
#include "../include/f_driver.hpp"

int main (const int argc, const char **argv) {
    if (argc != 2) {
        return (EXIT_FAILURE);
    }

    Fortran::Driver driver;
    int res = driver.parse(argv[1]);
    if (res == 0) driver.print();
    return res;
}