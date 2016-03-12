#include <iostream>
#include <fstream>
#include "./config.h"

using std::string;
using std::ifstream;
using std::endl;
using std::cout;



namespace config {
    config_settings read_config(string config_file_path){

        config_settings settings;

        ifstream infile;

        const int FILE_LINES = linecount(config_file_path);

        string *setting_values = new string[FILE_LINES];
        infile.open(config_file_path);

        string read_line = "";
        int current_line = 0;
        string temp_setting_name = "";
        string temp_setting_value = "";
        bool found_bracket = false;

        while (std::getline(infile, read_line)) {

            temp_setting_name = "";
            temp_setting_value = "";
            found_bracket = false;

            if (read_line[0] == '[') {

                for (int i = 1; i < read_line.length(); i++) {

                    if (read_line[i] == ']') {
                        // Need to add two to compensate for "]" ad "="
                        i++;
                        i++;
                        found_bracket = true;
                    }
                    if (!found_bracket) {
                        temp_setting_name = temp_setting_name + read_line[i];
                    } else {
                        temp_setting_value = temp_setting_value + read_line[i];
                    }

                }

                if (temp_setting_name == "name"){
                    settings.name = temp_setting_value;
                }else if (temp_setting_name == "email"){
                    settings.email_address = temp_setting_value;
                }else if (temp_setting_name == "cypher"){
                    settings.cypher = temp_setting_value;
                }else if (temp_setting_name == "timezone"){
                    settings.timezone = temp_setting_value;
                }else if (temp_setting_name == "knowrecipients"){
                    settings.known_recipients = temp_setting_value;
                }else {
                    cout << "Invalid setting name. - " << temp_setting_name << endl;
                }
                current_line++;
            }
        }


        infile.close();
        return settings;
    }

    int linecount(string input_file_path){
        int total_lines = 0;
        ifstream infile;
        infile.open(input_file_path);

        string read_line;
        while (std::getline(infile, read_line)) {

            if (read_line[0] == '[') {
                total_lines++;
            }
        }
        infile.close();
        return total_lines;
    }


    bool write_config(config_settings &settings, string config_file_path){
        bool result = false;

        std::ofstream config_file;

        config_file.open(config_file_path);
        if (config_file.is_open()) {
            config_file << "[name]=" << settings.name << endl;
            config_file << "[email]=" << settings.email_address << endl;
            config_file << "[cypher]=" << settings.cypher << endl;
            config_file << "[timezone]=" << settings.timezone << endl;
            config_file << "[knowrecipients]=" << settings.known_recipients << endl;

            config_file.close();
            result = true;
        }

        return result;
    };
}

