#include <iostream>

using std::string; using std::cout;

struct configStruct
{
    string first_name ,last_name, email , password , timezone;

};
bool writeConfig(string path);
int size_finder(string path);
using std::cout;
using std::string;
using std::fstream;
#include <fstream>
configStruct read_config(string config_file_path) ;