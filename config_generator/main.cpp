#include "configheader.h"

const string FILE_PATH = "C:\\Users\\Samantha\\Documents\\Schoolwork\\Spring2016\\C++\\Assignment5\\Config.txt";

int main(int argc, char *argv[]) {

  // initialize variables to hold given arguments.
  // Initialized in case of user not entering arguments on start
  string mode = "";
  string field = "";

  // retrieve argument 1 and cast as string, then test the given argument.
  // if anything other than edit or init is entered,
  // prompt until correct input is entered, then return acceptable input.
  mode = cast_str(argv[1]);
  mode = validateArg1(mode);

  // only if the first agument is edit, cast the second argument and validate
  if(mode == "edit"){
    field = cast_str(argv[2]);
    field = validateArg2(field);
  }

  // after all validation is complete, run either init or edit function
  if(mode == "init"){
    init();
  }else if(mode == "edit"){
    edit(field);
  }

  return 0;
}

/**
 * cast_str function casts a character pointer to a string
 */
string cast_str(char *arg){
  string str = static_cast<string>(arg);
  return str;
}

/*
 * validateArg1 function accepts a string and compares it to "init" and "edit."
 * if true, the string is returned without doing anything. Else, keep
 * prompting for input until an acceptable answer is given and then return
 */
string validateArg1(string arg) {
  while ((arg != "init") && (arg != "edit")) {
    cout << "To begin, please enter \"init\" or \"edit\":";
    cin >> arg;
  }
  return arg;
}

/*
 * Similar to validateArg1, accepts a string and compares it with the five field options of the
 * ConfigFile Struct. If true, return with no action. Else, prompt for new input until user provides
 * valid entry and then return.
 */
string validateArg2(string arg) {
  bool found = false;
  while(arg != "name" && arg != "email" && arg != "cypher" && arg != "timezone" && arg != "filepath"){
    cout << "To edit, please enter one of the following fields; \"name\", \"email\", \"cypher\", \"timezone\","
              " \"filepath\": ";
    cin >> arg;
  }
  return arg;
}

void init() {

  cout << "\nCONFIG FILE CREATION\n\n";

  // declare struct
  configio::ConfigFile config;

  // initialize struct fields by calling the get_value function and returning a string value
  config.first_name = get_value(f_name);
  config.email = get_value(email);
  config.cypher = get_value(cypher);
  config.timezone = get_value(timezone);
  config.filepath = get_value(f_path);

  //write config to file and print success status
  if(configio::write_config(config.filepath, config)){
   cout << "( File Created )" << endl;
  }else {
    cout << "( Error Creating File )" << endl;
  }
}

/**
 * get_value will return dtring values for ConfigFile fields
 */
string get_value(fields field){
  bool isFPath = false;

  // Determine whether current field is f_path (handled differently than other fields)
  if(field == f_path){
    isFPath = true;
    cout << "\tEnter a value for the " << FIELDS[field] << " field "
           "( Pressing \"Enter\" will set filepath to default location ):";
  } else {
    cout << "\tEnter a value for the " << FIELDS[field] << " field:";
  }
  string input = "";
  getline(cin, input);

  // if the user pressed Enter without entering input, determine whether current field
  // is fpath. If isFPath, start path handling.
  // Else, if not isFPath, prompt the user for a field value again
  if (input == "") {
    if (isFPath){
        handlePath();
    } else {
      while(input == "") {
        cout << "( Invalid Input )" << endl;
        cout << "\tEnter a value for the " << FIELDS[field] << " field:";
        getline(cin, input);
      }
    }
  }
  return input;
}

/* handlePath function prompts user a second time before overwriting default config file
 * if user_confirm is true, filepath is set to default location
 * if false, user enters new path and path is tested before being returned
 */
string handlePath() {
  string path;

  // if user confirms that they want to overwrite the default template file, return the constant path
  if (user_confirm()) {
    path = FILE_PATH;
    cout << "( File path set to default location )"  << endl;

  // else, if user has changed their mind, give a option to enter new file path.
  // After new file path is given by user, test path and return if good.
  } else {
    cout << "\tEnter a new value for the " << FIELDS[f_path] << " field:";
    getline(cin, path);
    while(!ifGood(path)){
      cout << "( Invalid input )" << endl;
      cout << "\tEnter a new value for the " << FIELDS[f_path] << " field:";
      getline(cin, path);
    }
    cout << "( New file path set )" << endl;
  }

  return path;
}

/* if user has chosen to overwrite the default file,
 * prompt a second time before actually overwriting
 */
bool user_confirm(){
  cout << "\tAre you sure you want to overwrite the default config file?" << endl;
  cout << "( " << FILE_PATH << " )" << endl << "\tyes or no: ";
  string input;
  getline(cin, input);
  while (input != "yes" && input != "no") {
    cout << "( Invalid input )" << endl << "\tPlease enter \"yes\" or \"no\": ";
    getline(cin, input);
  }
  bool isOverwriting = false;
  if (input == "yes") {
    isOverwriting = true;
    cout << "( You selected to overwrite the default file )" << endl;
  } else {
    cout << "( You selected not to overwrite the default file )" << endl;
  }
  return isOverwriting;
}

/*
 * ifGood accepts a file path string and determines whether the path is locatable
 */
bool ifGood(string filepath){
  ifstream file(filepath);
  bool status = false; // initialize to false and only switch to true if file can be opened
  if(file){
    status = true; // file can be opened
  }
  file.close();
  return status;
}


void edit(string field){

  cout << "\nCONFIG FILE EDIT\n\n";
  cout << "\tEnter a filepath, or press 'Enter' to open the default path: ";
  string path;
  getline(cin, path);
  if(path.length() == 0){
    path = FILE_PATH;
  }

  //read_config function reads lines of a file, stores data in struct and returns struct pointer
  configio::ConfigFile *config_ptr = configio::read_config(path);
  configio::ConfigFile config = *config_ptr;

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
