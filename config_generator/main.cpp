#include "configheader.h"

const string FILE_PATH = "C:\\Users\\Samantha\\ClionProjects\\Assignment2-Config-Files\\Config.txt";

int main(int argc, char *argv[]) {
  // initialize variables with given arguments
  string arg1 = "";
  if(argc > 1){
    arg1 = static_cast<string>(argv[1]);
  }
  string arg2 = "";
  if(argc == 3){
    arg2 = static_cast<string>(argv[2]);
  }

  if(arg1 == "init"){
    init();
  }else if(arg1 == "edit"){
    if(arg2 == "name" || arg2 == "email" || arg2 == "password" || arg2 == "timezone" || arg2 == "filepath") {
        //edit(arg2);
    }else{
      do{
        cout << "You did not enter the right argument. To edit a field, enter \"name\", \"email\", \"password\", "
          << "\"timezone\", or \"filepath\": ";
        cin >> arg2;
      }while(arg2 != "name" && arg2 != "email" && arg2 != "password" && arg2 != "timezone" && arg2 != "filepath");
      //edit(arg2);
    }
  }else{
    do{
      cout << "You did not provide valid arguments. Enter \"init\" to create a new config file or \"edit\""
                << " to change an existing one: ";
      cin >> arg1;
    }while(arg1 != "init" && arg1 != "edit");
    if(arg1 == "init"){
      init();
    }else{
      cout << "Enter one of the following fields to edit its value: \"name\", \"email\", \"password\","
                << " \"timezone\", \"filepath\"";
      cin >> arg2;
      while(arg2 != "name" && arg2 != "email" && arg2 != "password" && arg2 != "timezone" && arg2 != "filepath") {
        cout << "You did not enter an acceptable argument. Please enter one of the following: \"name\", \"email\", "
                << "\"password\", \"timezone\",\n\"filepath\": ";
        cin >> arg2;
      }
      //edit(arg2);
    }
  }
  return 0;
}

void init() {
  const int SIZE = 5;
  const string PROMPTS[SIZE] = {"Please enter your first and last name: ", "Please enter your email address: ", "Please enter"
    " your password: ", "Please enter a timezone offset: ", "Enter a file path for the config file: "};

  cout << "\nCONFIG FILE CREATION\n\n";

  string values[SIZE];
  // prompt for all questions that require input.
  for(int i = 0; i < SIZE; i++) {
    cout << "\t" + PROMPTS[i];
    getline(cin, values[i]);
    while(values[i].length() == 0) {
      if(i == (SIZE - 1)){
        values[i] = FILE_PATH;
        cout << "\t( File path set to default location )";
      }else{
        cout << "You did not enter any input. Please try again.\n";
        cout << PROMPTS[i];
        cin >> values[i];
      }
    }
  }

  // create struct and assign user input to fields
  configio::ConfigFile config;
  config.first_name = values[0];
  config.email = values[1];
  config.cypher = values[2];
  config.timezone = values[3];
  config.filepath = values[4];

  if(configio::write_config(config.filepath, config)){
   cout << "File Created";
  }else {
    cout << "Error Creating File";
  }
}


/*
void edit(string field){
  const int SIZE = 5;

  cout << "\nCONFIG FILE EDIT\n\n";
  cout << "\tEnter a filepath, or press 'Enter' to open the default path: ";
  string path;
  getline(cin, path);
  if(path.length() == 0){
    path = FILE_PATH;
  }

  //read_config function reads lines of a file, stores data in struct and returns struct pointer
  configio::ConfigFile* configptr = configio::read_config(path);
  configio::ConfigFile config = *configptr;

  // prompt user to change given field
  cout << "\tEnter a new value for the " + field + " field: ";
  if(field == "name"){
    getline(cin, config.first_name);
  }else if(field == "email"){
    getline(cin, config.email);
  }else if(field == "password"){
    getline(cin, config.cypher);
  }else if(field == "timezone"){
    getline(cin, config.timezone);
  }

 // User is always given the option to change the filepath
 // If the user presses enter or gives an invalid path, the original filepath is kept
  cout << "\tEnter a new value for the filepath field or press \"Enter\" to keep the current path";
  getline(cin, path);
  if(path.length() != 0){
    ofstream file(path);
    if(file.good()){
      config.filepath = path;
    }
    file.close();
  }
  if(configio::write_config(config.filepath, config)){
    cout << "File Updated" << endl;
  }else {
    cout << "Error in creating file";
  }
}
*/
