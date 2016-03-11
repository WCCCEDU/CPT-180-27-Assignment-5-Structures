#include "structures_header.h"
// Project should read the Config into the struct then Output the Struct to the file
int main() {
    string s = "C:\\Users\\Hanko\\Documents\\C++ Files\\Assignment3\\config1.txt";
    writeConfig(s);
    return 0;
}
int size_finder(string path)
{
    int count = 0;
    string line;
    fstream myFile(path);
    while(getline(myFile,line))
    {
        count++;
    }
    return count;
}
configStruct read_config(string config_file_path) {
    configStruct info;
    int const SIZE = size_finder(config_file_path) + 1;
    fstream file(config_file_path);
    if (file.is_open()) {
        string myArray[SIZE];
        cout <<"Config Read\n";
        for (int i = 0; i < SIZE; ++i) {
            file >> myArray[i];
        }
        info.first_name = myArray[0];
        info.last_name = myArray[1];
        info.email = myArray[2];
        info.password = myArray[3];
        info.timezone = myArray[4];

return info;
    }
}
bool writeConfig(string path)
{
    fstream file(path);
    configStruct data = read_config("C:\\Users\\Hanko\\Documents\\C++ Files\\Assignment3\\config.txt");
    if(!file)
    {
        cout <<"File Didn't Work\n";
        return false;
    }else{
        cout <<"Struct Output to file\n";
        file << data.first_name << '\n' << data.last_name << '\n' << data.email << '\n' << data.password << '\n' << data.timezone;
        file.close();
        return true;

    }
}

