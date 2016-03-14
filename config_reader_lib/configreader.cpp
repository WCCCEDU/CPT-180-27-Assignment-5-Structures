#include "./config.h"

namespace config_gen {


    config read_config(std::string config_file_path) {
        std::ifstream inputFile;
        inputFile.open(config_file_path);
        config info_file;
        if (inputFile.is_open()) {
            inputFile >> info_file.first_name;
            inputFile >> info_file.last_name;
            inputFile >> info_file.email;
            inputFile >> info_file.cypher;
            inputFile >> info_file.timezone;
        }


        return info_file;

    }
    bool write_config(std::string path, config data);

}


