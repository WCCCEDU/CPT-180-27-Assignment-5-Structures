
#include <string>
#include "reader.h"
#include <fstream>

using namespace std;

static config config_lib::read_config(string config_file_path)
{
   config arr;

    ifstream inFile(config_file_path);

//    int count = 0;
//    string line;
//    for (count = 0; getline(inFile, line); ++count);
//
//    inFile.close();

    //inFile.open(config_file_path);

    getline(inFile, line);
    arr.name = line;
    getline(inFile, line);
    arr.email = line;
    getline(inFile, line);
    arr.cypher = line;
    getline(inFile, line);
    arr.timezone_offset = line;
    arr.file_path = config_file_path;


    inFile.close();

    return arr;

}

static bool config_lib::write_config(string config_file_path, config_lib::config write){
    ofstream outFile;
    outFile.open(config_file_path);
    config write;
    if (outFile.open()) {
        outFile >> write.name;
        outFile >> write.email;
        outFile >> write.cypher;
        outFile >> write.timezone_offset;
        outFile >> write.file_path;
    }

    outFile.close();
    return true;
}