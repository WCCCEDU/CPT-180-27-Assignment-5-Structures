#include <iostream>

using std::string; using std::cout;

struct configStruct
{
    string first_name ,last_name, email , password , timezone;

};
bool writeConfig(string path , configStruct data);
int size_finder(string path);
using std::cout;
using std::cin;
using std::string;
using std::fstream;
#include <fstream>
configStruct read_config(string config_file_path) ;
configStruct create_config();
configStruct edit_config(string file , string choice);