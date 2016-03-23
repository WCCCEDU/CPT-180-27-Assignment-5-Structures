#include <iostream>
#include <fstream>
#include "./config.h"


using std::string;
using std::ifstream;
namespace config_reader {
    string *read_config(string config_file_path) {

        ifstream inputfile;
        inputfile.open("/Users/jon/Desktop/C++repos/CPT-180-27-Config-Generator/config.txt");

        // Count Lines in file by reading file
        int number_of_lines = 0;
        while (!inputfile.eof()) {
            string thing;
            getline(inputfile, thing);
            number_of_lines++;
        }
        inputfile.close();

        inputfile.open("/Users/jon/Desktop/C++repos/CPT-180-27-Config-Generator/");

        string *config_input = new string[number_of_lines];

        if (inputfile.is_open()) {
            int i = 0;
            while (!inputfile.eof()) {
                string config_line;
                getline(inputfile, config_line);
                config_input[i] = config_line;
                i++;
            }
        }
        inputfile.close();
        return config_input;
    }
}
