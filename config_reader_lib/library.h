#include <iostream>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;

struct Config{
    string first_name;
    string last_name;
    string email;
    string timezone;
    string cypher;
};

namespace config_generator {
    Config* read_config(string config_file_path);
    bool write_config(string config_file_path, Config data);
}
