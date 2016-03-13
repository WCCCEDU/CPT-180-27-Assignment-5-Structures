#include <iostream>
#include <fstream>
#include "./libraries.h"


using  std::string;

namespace config_reader {

    string *read_config(string config_file_path) {


        std::ifstream file(PATH);
        file.open(PATH);

        if (file.is_open()) {
            string *config_Array[4];
            for (int i = 0; i < 4; i++) {
                file >> *config_Array[i];
            }
            config_Array[0] = config.name;
            config_Array[1] = config.email;
            config_Array[2] = config.cypher;
            config_Array[3] = config.timezone;
        }
    }
}
