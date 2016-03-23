#include <iostream>
#include <fstream>

using std::string;

struct config{
    string name;
    string email;
    string timeZoneDiff;
    string cypher;
    string knownRecipientsFile;
};

void init();
