#include <iostream>
#include <fstream>
#include "Assignment3-Libraries.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;

enum fields {f_name, email, cypher, timezone, f_path};
const string FIELDS[5] = {"name", "email", "cypher", "timezone", "filepath"};

bool ifGood(string filepath);        // checks whether file exists/was successfully created
string cast_str(char *arg);          // casts character pointer to string
bool user_confirm();                 // prompts the user before overwriting given files
string handlePath();                 // handles overwriting old path and retreiving new ones

string validateArg1(string arg);     // makes sure arg 1 is equal to init or edit
string validateArg2(string arg);     // makes sure arg 2 is equal to a file path

string get_value(fields field);      // retreives new value from the user for struct field

void init();                         // creates a new ConfigFile struct and writes its data to a file

void edit(string field);             /* creates a ConfigFile struct from an existing file and edits it before writing to
                                      * new file or overwriting old one */
