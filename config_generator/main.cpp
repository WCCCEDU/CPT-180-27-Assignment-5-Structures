// Configuration editor
// Command line utiltiy to create configuration files
// Valid arguments are init and edit

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "./main.h"

using namespace config;
using std::cout;
using std::endl;
using std::string;
using std::cin;

const string CONFIG_FILE_PATH = "./config/app.cfg";


int main(int argc, char *argv[]) {

    string argument1 = "";
    // Make sure that the argument isn't empty
    if (argv[1] != nullptr) {
        argument1 = static_cast<string>(argv[1]);

        if (argument1 == "init") {

            // initialize the config file
            initialize_config(CONFIG_FILE_PATH);

        } else if (argument1 == "edit") {
            // edit the config file


            config_settings settings = read_config(CONFIG_FILE_PATH);

            // Check if the second argument is blank
            string command_argument = "";
            if (argv[2] != nullptr) {
                command_argument = static_cast<string>(argv[2]);
                prompt_for_values(settings, true, command_argument);
                if (!write_config(settings, CONFIG_FILE_PATH)) {
                    cout << "Error writing config." << endl;
                }
            } else {
                // No setting value was given


                prompt_for_values(settings, true);


                if (!write_config(settings, CONFIG_FILE_PATH)) {
                    cout << "Error writing config." << endl;
                }

            }


        } else {
// invalid argument
            cout << "Invalid argument us int or edit." << endl;
            cout << "When using edit either enter a value to edit" << endl;
            cout << "(name, email, cypher, timezone, or knownrecipients)." << endl;
            cout << "If no setting is entered then the settings will be cycled through" << endl;
        }
    } else {
        cout << "Invalid argument us int or edit." << endl;
        cout << "When using edit either enter a value to edit" << endl;
        cout << "(name, email, cypher, timezone, or knownrecipients)." << endl;
        cout << "If no setting is entered then the settings will be cycled through" << endl;
    }

    return 0;
}

int initialize_config(string config_file_path) {


    config_settings settings;

    prompt_for_values(settings, false);


    if (!write_config(settings, CONFIG_FILE_PATH)) {
        cout << "Error writing config." << endl;
    }

    return 0;
}

void prompt_for_values(config_settings &settings, bool edit_mode, string edit_setting) {

    // Create a backup of the config file

    const string FILE = CONFIG_FILE_PATH;
    const string BACKUP_FILE = FILE + ".backup";

    int result = 0;
    if (edit_mode){
        // Delete the previous backup if it exists
        std::remove(BACKUP_FILE.c_str());

        // Create a backup of the config before it is edited
        result = std::rename(FILE.c_str(), BACKUP_FILE.c_str());
    }


    if (result == 0) {

        string name = "";

        if (edit_mode) {
            if (edit_setting == "name" || edit_setting == "none") {

                cout << "Enter your name (first and last):" << endl;
                cout << "Current setting is " << settings.name << ". To keep this value hit enter." << endl;

                getline(cin, name);

                if (name != "") {
                    settings.name = name;
                }

            }

        } else {
            cout << "Enter your name (first and last):" << endl;

            getline(cin, name);

            while (name == "") {
                cout << "The name can't be blank." << endl;
                cout << "Enter your name (first and last):" << endl;

                getline(cin, name);
            }
            settings.name = name;
        }


        string email = "";

        if (edit_mode) {
            if (edit_setting == "email" || edit_setting == "none") {

                cout << "Enter your email address:" << endl;
                cout << "Current setting is " << settings.email_address << ". To keep this value hit enter." << endl;

                getline(cin, email);

                if (email != "") {
                    settings.email_address = email;
                }

            }

        } else {
            cout << "Enter your email address:" << endl;

            getline(cin, email);

            while (email == "") {
                cout << "The email can't be blank." << endl;
                cout << "Enter your email address:" << endl;

                getline(cin, email);
            }
            settings.email_address = email;

        }


        string cypher = "";

        if (edit_mode) {
            if (edit_setting == "cypher" || edit_setting == "none") {
                cout << "Enter your unique cypher (password):" << endl;
                cout << "Current setting is.. You thought that I was going to show it didn't you. " <<
                "To keep the current value hit enter." << endl;

                getline(cin, cypher);

                if (cypher != "") {
                    settings.cypher = cypher;
                }

            }
        } else {
            cout << "Enter your unique cypher (password):" << endl;
            getline(cin, cypher);

            while (cypher == "") {
                cout << "The cypher can't be blank." << endl;
                cout << "Enter your unique cypher (password):" << endl;

                getline(cin, cypher);
            }
            settings.cypher = cypher;

        }


        string timezone = "";

        if (edit_mode) {
            if (edit_setting == "timezone" || edit_setting == "none") {
                cout << "Enter your timezone-offset (example -5:00):" << endl;
                cout << "Current setting is " << settings.timezone << ". To keep this value hit enter." << endl;

                getline(cin, timezone);

                if (timezone != "") {
                    settings.timezone = timezone;
                }

            }

        } else {
            cout << "Enter your timezone-offset (example -5:00):" << endl;
            getline(cin, timezone);

            while (timezone == "") {
                cout << "The timezone can't be blank." << endl;
                cout << "Enter your timezone-offset (example -5:00):" << endl;

                getline(cin, timezone);
            }
            settings.timezone = timezone;
        }


        string known_recipients = "";

        if (edit_mode) {
            if (edit_setting == "knownrecipients" || edit_setting == "none") {
                cout << "Enter path to knownrecipients file:" << endl;
                cout << "Current setting is " << settings.known_recipients << ". To keep this value hit enter." << endl;

                getline(cin, known_recipients);

                if (known_recipients != "") {
                    settings.known_recipients = known_recipients;
                }

            }
        } else {
            cout << "Enter path to knownrecipients file:" << endl;
            cout << "(hit enter for the default ./knownrecipients.txt)" << endl;

            getline(cin, known_recipients);

            if (known_recipients == "") {
                known_recipients = "./knownrecipients.txt";
            }
            settings.known_recipients = known_recipients;
        }

    } else {
        cout << "Error backing up original config file";
    }

}