#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

struct config {
    std::string first_name;
    std::string last_name;
    std::string cypher;
    std::string email;
    std::string timezone;
    std::string file_path;
};

namespace config_gen {
    config read_config(std::string config_file_path);
    bool write_config(std::string path, config data);
}