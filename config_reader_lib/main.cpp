
#include "./Assignment3-Libraries.h"

namespace configio{

  // Function returns a pointer to a ConfigFile struct
  ConfigFile* read_config(string file_path){

    //get number of lines in file
    // number of lines divided by two because file input will be distributed into two parallel arrays
    //int num_lines = line_count(file_path);
    const int SIZE = 5;

    // declare input file and open path
    ifstream file(file_path);

    // declare parallel arrays for file input
    string headers[SIZE];
    string values[SIZE];

    //read lines of file and store in array
    int i = 0;
    do{
      getline(file, headers[i]);
      getline(file, values[i]);
      cout << headers[i] << endl; //test for lines being read correctly from file
      cout << values[i] << endl;
      i++;
    } while(!file.eof());

    // file closes after finished reading input
    file.close();

    // Create string pointer variable and assign address of array
    ConfigFile config;

    // Still needs error checking to make sure fields are in correct order in file
    config.first_name = values[0];
    config.email = values[1];
    config.cypher = values[2];
    config.timezone = values[3];
    config.filepath = values[4];

    ConfigFile* configptr = &config;
    return configptr;
  }

  int line_count(string path){
    ifstream file(path);
    string line = "";
    int count = 0;
    while(getline(file, line)){
      count++;
    }
    file.close();
    return count;
  }

  bool write_config(string path, ConfigFile config){
    const int SIZE = 5;
    const string HEADERS[5] = {"[name]", "[email]", "[cypher]", "[timezone]", "[filepath]"};
    const string VALUES[5] = {config.first_name, config.email, config.cypher, config.timezone, config.filepath};
    ofstream file(path);
    bool flag = false;
    if(file.good()) {
      for(int i = 0; i < SIZE; i++){
        file << HEADERS[i] << endl;
        file << "\t" << VALUES[i] << endl;
      }
      flag = true;
    }
    file.close();
    return flag;
  }
}