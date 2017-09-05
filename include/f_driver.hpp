#ifndef __FDRIVER_HPP__
#define __FDRIVER_HPP__

#include <string>
#include <cstddef>
#include <istream>

#include "f_scanner.hpp"
#include "f_parser.tab.hh"

namespace Fortran {

    class Driver {
      public:
        Driver() = default;

        virtual ~Driver();

        /** 
        * parse - parse from a file
        * @param filename - valid string with input file
        */
        void parse(const char *filename);

        /** 
        * parse - parse from a c++ input stream
        * @param is - std::istream&, valid input stream
        */
        void parse(std::istream &iss);

        void add_upper();
        void add_lower();
        void add_word(const std::string &word);
        void add_newline();
        void add_char();

        std::ostream& print(std::ostream &stream);

      private:
        void parse_helper(std::istream &stream);

        std::size_t  chars = 0;
        std::size_t  words = 0;
        std::size_t  lines = 0;
        std::size_t  uppercase = 0;
        std::size_t  lowercase = 0;

        Parser *parser = nullptr;
        Scanner *scanner = nullptr;

        /** define some pretty colors **/
        const std::string red  = "\033[1;31m";
        const std::string blue = "\033[1;36m";
        const std::string norm = "\033[0m";
    };
}
#endif /* END __FDRIVER_HPP__ */