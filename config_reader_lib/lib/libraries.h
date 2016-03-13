#include <iostream>
#include <fstream>

struct Config{
    std::string name;
    std::string email;
    std::string cypher;
    std::string timezone;
};
namespace  config_reader{
    std::string* read_config(std::string config_file_path);
}
