#include <iostream>
#include <string>
#include <fstream>
#include "config_reader_lib/reader.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int main(int argc, char *argv[]) {

    if(static_cast<string>(argv[1]) == "init"){

        config_lib::config write;

        while (write.name == "") {
            cout << "Enter your name: ";
            getline(cin, write.name);
        }

        while (write.email == ""){
            cout << "Enter your e-mail: ";
            getline(cin, write.email);
        }

        while (write.cypher == ""){
            cout << "Enter your cypher: ";
            getline(cin, write.cypher);
        }

        while (write.timezone_offset == ""){
            cout << "Enter you timezone offset: ";
            getline(cin, write.timezone_offset);
        }

        cout << "Enter your file path: ";
        getline(cin, write.file_path);
        if (write.file_path == ""){
            write.file_path = "knownrecipients.txt";
        }



        config_lib::write_config(write.file_path, write);

    }else if(static_cast<string>(argv[1]) == "edit"){

        config_lib::config read;
        if(static_cast<string>(argv[2]) == "name"){
            ifstream inFile;
            inFile.open(read.file_path);




        }
    }

    return 0;
}