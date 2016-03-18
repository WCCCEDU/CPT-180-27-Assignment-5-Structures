#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::ofstream;
using std::ifstream;

//const string CONFIG_FILE_PATH = "config.txt";
//const string NEW_CONFIG_FILE_PATH = "Editconfig.txt";

void init() {

    string Name;
    cout << "Enter name:" << endl;
    cin >> Name;
    while (Name == "") {
        cout << "Re-Enter name" << endl;
        cin >> Name;
                }

    string email;
    cout << "Enter email:" << endl;
    cin >> email;
    while (email == "") {
        cout << "Re-Enter email" << endl;
        cin >> email;
    }

    string cypher;
    cout << "Enter password:" << endl;
    cin >> cypher;
    while (cypher == "") {
        cout << "Re-Enter password" << endl;
        cin >> cypher;
    }

    string timeZoneDiff;
    cout << "Enter Time Zone Differential:" << endl;
    cin >> timeZoneDiff;
    while (timeZoneDiff == "") {
        cout << "Re-Enter Time Zone Differential" << endl;
        cin >> timeZoneDiff;
    }

    string knownRecipientsFile;
    cout << "Enter Known recipients file path" << endl;
    cin >> knownRecipientsFile;
    if (knownRecipientsFile == "") {
        knownRecipientsFile = "knownrecipient.txt";
    } else
        knownRecipientsFile;

    config user_config;
    user_config.name = name;
    user_config.cypher = cypher;
    user_config.email = email;
    user_config.timeZoneDiff = timeZoneDiff;
    user_config.knownRecipientsFile = knownRecipientsFile;

}
void mainconfiglib (char *argv[]) {
    if (static_cast<string>(argv[1]) == "init") {
        init();
    }
    else if (static_cast<string>(argv[1]) == "edit") {
        ifstream inputfile;
        inputfile.open(CONFIG_FILE_PATH);

        string Name;
        string email;
        string cypher;
        string timeZoneDiff;
        string knownRecipientsFile;

        // read config file
        inputfile >> Name;
        inputfile >> email;
        inputfile >> cypher;
        inputfile >> timeZoneDiff;
        inputfile >> knownRecipientsFile;

        config edit_config;
        edit_config.Name = Name;
        edit_config.email = email;
        edit_config.cypher = cypher;
        edit_config.timeZoneDIff = timeZoneDiff;
        edit_config.knownRecipientsFile;

        inputfile.close();

        if (static_cast<string>(argv[2]) == "name") {
            cout << "Edit  name:" << endl;
            cin >> Name;
            while (Name == "") {
                cout << "Re-Enter name" << endl;
                cin >> Name;
            }
        }

        if (static_cast<string>(argv[2]) == "email") {
            cout << "edit email:" << endl;
            cin >> email;

            while (email == "") {
                cout << "Re-Enter email" << endl;
                cin >> email;
            }
        }

        if (static_cast<string>(argv[2]) == "password") {
            cout << "edit password:" << endl;
            cin >> cypher;

            while (cypher == "") {
                cout << "Re-Enter password" << endl;
                cin >> cypher;
            }
        }

        if (static_cast<string>(argv[2]) == "timezone") {
            cout << "edit Time Zone Differential:" << endl;
            cin >> timeZoneDiff;

            while (timeZoneDiff == "") {
                cout << "Re-Enter Time Zone Differential" << endl;
                cin >> timeZoneDiff;
            }
        }

        if (static_cast<string>(argv[2]) == "knownrecipients") {
            cout << "Enter Known recipients file path" << endl;
            cin >> knownRecipientsFile;

            if (knownRecipientsFile == "") {
                knowRecipientsFile = "knownrecipient.txt";

            } else new_outputfile << "[knowrecipients] = " << knownRecipientsFile << endl;
        }
    }
}



